#!/bin/sh
# quadra_fw_upgrade.sh: safe wrapper around nvmefw for NETINT Quadra firmware upgrades on FreeBSD.
#
# usage: quadra_fw_upgrade.sh [-y] [-n] NVME_CONTROLLER IMAGE
#   e.g. sudo ./quadra_fw_upgrade.sh /dev/nvme1 nor_flash_v5.9.0_RC1-Quadra.bin
#   -n  dry run: do all the checks and print the plan, send nothing
#   -y  do not ask for confirmation
#
# It checks that
#   - it runs as root and nvmefw (same directory, or in PATH) exists,
#   - the device is a NETINT Quadra (vendor 0x1d82, model QuadraT*),
#   - the image looks valid (size, revision text) and shows both revisions,
#   - no process has the card open (a running session must not be interrupted),
# then raises nvme(4)'s admin timeout to 120 s (the burn takes about a minute and
# the default is 60 s; the driver resets a controller whose command times out),
# runs "nvmefw flash", and restores the timeout.
#
# Choosing the right image is NOT automated: NETINT ships one image per
# "persistent configuration" letter (nor_flash_*-Quadra.bin, -C, -E, -F, -G).
# quadra_auto_upgrade.sh on Linux reads the letter from the card (vendor admin
# opcode 0xC2, or log page 194 on newer firmware); an old firmware rejects 0xC2 and the
# plain "-Quadra.bin" is used. Use the same rule here.
set -eu

yes=0; dry=0
while getopts yn o; do
    case $o in
    y) yes=1 ;;
    n) dry=1 ;;
    *) echo "usage: $0 [-y] [-n] /dev/nvmeN IMAGE" >&2; exit 2 ;;
    esac
done
shift $((OPTIND - 1))
[ $# -eq 2 ] || { echo "usage: $0 [-y] [-n] /dev/nvmeN IMAGE" >&2; exit 2; }
dev=$1; img=$2

[ "$(id -u)" -eq 0 ] || { echo "must run as root" >&2; exit 1; }
here=$(cd "$(dirname "$0")" && pwd)
nvmefw=$here/nvmefw
[ -x "$nvmefw" ] || nvmefw=$(command -v nvmefw) || { echo "nvmefw not found" >&2; exit 1; }
[ -c "$dev" ] || { echo "$dev is not a character device (use the controller, e.g. /dev/nvme1)" >&2; exit 1; }
[ -r "$img" ] || { echo "cannot read $img" >&2; exit 1; }
unit=${dev#/dev/nvme}
case $unit in ''|*[!0-9]*) echo "expected /dev/nvmeN, got $dev" >&2; exit 1 ;; esac

echo "== device"
info=$("$nvmefw" info "$dev")
echo "$info"
echo "$info" | grep -q '^VID *0x1d82' || { echo "not a NETINT device, refusing" >&2; exit 1; }
echo "$info" | grep -q '^MN *QuadraT' || { echo "model is not a QuadraT*, refusing" >&2; exit 1; }

echo "== image"
"$nvmefw" check "$dev" "$img"

echo "== sessions"
busy=$(fstat "$dev" "${dev}n1" 2>/dev/null | awk 'NR > 1 {print $2, $1, $3}' | sort -u || true)
if [ -n "$busy" ]; then
    echo "these processes have the card open, stop them first:" >&2
    echo "$busy" >&2
    exit 1
fi
echo "no process has the card open"

if [ "$dry" -eq 1 ]; then
    echo "== plan (dry run, nothing is sent)"
    "$nvmefw" plan "$dev" "$img" | sed -n '1,2p;$p'
    exit 0
fi

if [ "$yes" -ne 1 ]; then
    printf 'This writes the card'"'"'s flash. Power must not be lost. Type yes to continue: '
    read -r ans
    [ "$ans" = yes ] || { echo "aborted"; exit 1; }
fi

old=$(sysctl -n "dev.nvme.$unit.admin_timeout_period")
trap 'sysctl dev.nvme.'"$unit"'.admin_timeout_period="$old" >/dev/null 2>&1 || true' EXIT INT TERM
sysctl "dev.nvme.$unit.admin_timeout_period=120" >/dev/null
echo "admin timeout raised from $old s to 120 s (restored on exit)"

"$nvmefw" flash "$dev" "$img" --yes
echo
echo "Next: power-cycle the host (a reboot is enough on this machine), then check:"
echo "  $nvmefw info $dev   and   ni_rsrc_list"
