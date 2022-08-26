function getfbsduvers ()
	local osrel = io.open("/etc/os-release")
	if (not osrel) then return nil end
	local reldat = {}
	for line in osrel:lines() do
		local k, v = string.match(line,
			'%s*(.+)%s*=%s*"?%s*([^"]+)%s*"?')
		if (k and v) then reldat[k] = v end
	end
	osrel:close()
	if (not reldat["ID"] or reldat["ID"] ~= "freebsd") then return nil end
	return reldat["VERSION"]
end

function printwarning (uvers, required)
	local msg=[=[
======
Message from $pkg:

!!! ATTENTION !!!

You are currently running FreeBSD $vcurr.

Correct operation of $pkg requires a bugfix that was delivered
in $vreq.

This package is probably installed as a dependency of some screen locker,
and without the bugfix, YOU WILL PROBABLY BE UNABLE TO UNLOCK YOUR SCREEN.

Please use freebsd-update(8) to update your system before you continue.

See also:
<URL:https://security.FreeBSD.org/advisories/FreeBSD-EN-22:19.pam_exec.asc>
]=]
	local warning = string.gsub(msg, '$(%w+)',
		{pkg = pkg_name, vcurr = uvers, vreq = required})
	pkg.print_msg(warning)
end

fbsduvers = getfbsduvers()
if (fbsduvers and string.match(fbsduvers, '-RELEASE')) then
	umaj = tonumber(string.match(fbsduvers, '^[0-9]+'))
	umin = tonumber(string.match(fbsduvers, '%.([0-9]+)-'))
	uplv = tonumber(string.match(fbsduvers, '-p([0-9]+)'))
	if (not uplv) then uplv = 0 end
	if (umaj == 13 and umin <= 1) then
		if (umin == 0 and uplv < 12) then
			printwarning(fbsduvers, "13.0-RELEASE-p12")
		elseif (umin == 1 and uplv < 1) then
			printwarning(fbsduvers, "13.1-RELEASE-p1")
		end
	end
end
