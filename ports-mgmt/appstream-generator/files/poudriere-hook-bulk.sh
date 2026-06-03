#!/bin/sh
# /usr/local/etc/poudriere.d/hooks/bulk.sh

# Variables to be set by operator
#
# The location for the generated data
# This should be persistent across "poudriere bulk" runs and be specific to
# the given jail-ports-set combination (i.e. have ${MASTERNAME} in the path)
ASGEN_WORKSPACE=/asgen/${MASTERNAME}
# The URL to the repository root (which will contain AppStreamComponents.xml.gz)
REPOSITORY_URL=https://pkg.freebsd.org/FreeBSD:16:amd64/latest

status="$1"
shift

if [ "$status" != "done" ]; then
	exit 0
fi

echo "==> Running AppStream post-bulk hook"

ASGEN_CMD=/usr/local/bin/appstream-generator
ARCH=$(uname -p)

# PACKAGES ends with "/.latest", so we chop it first
if [ "$(basename ${PACKAGES})" == ".latest" ]; then
	suite=$(basename $(dirname ${PACKAGES}))
else
	suite=$(basename ${PACKAGES})
fi

asgen_config=$(cat<<EOF
{
"ProjectName": "FreeBSD",
"MediaBaseUrl": "${REPOSITORY_URL}/media",
"ArchiveRoot": "${POUDRIERE_DATA}/packages",
"Backend": "freebsd",
"Suites": {
  "$suite": {
    "sections": ["default"],
    "architectures": ["$ARCH"]
    }
  }
}
EOF
)

# Create the workspace dir if not exist.
mkdir -p "${ASGEN_WORKSPACE}"

# Write the config to the workspace dir.
echo "$asgen_config" > ${ASGEN_WORKSPACE}/asgen-config.json

# Generate the metainfo
echo Running $ASGEN_CMD -w "${ASGEN_WORKSPACE}" run "$suite"
$ASGEN_CMD -w "${ASGEN_WORKSPACE}" run "$suite"

# TODO: Upstream recommends running cleanup once in a week
$ASGEN_CMD -w "${ASGEN_WORKSPACE}" cleanup

# Symlink the metadata archives back to Poudriere repository root
for f in ${ASGEN_WORKSPACE}/export/data/${suite}/default/*.gz; do
	dest_f=AppStream$(basename ${f} | sed s/-${ARCH}//)
	ln -fs ${f} ${PACKAGES}/${dest_f}
done

# Symlink the media dir
ln -fs "${ASGEN_WORKSPACE}/export/media" "${PACKAGES}/media"

# Follow Poudriere layout if ATOMIC_PACKAGE_REPOSITORY is enabled
if [ "$(basename ${PACKAGES})" == ".latest" ]; then
	for f in ${ASGEN_WORKSPACE}/export/data/${suite}/default/*.gz; do
		dest_f=AppStream$(basename ${f} | sed s/-${ARCH}//)
		ln -fs ${f} ${PACKAGES_ROOT}/${dest_f}
	done
	ln -fs "${ASGEN_WORKSPACE}/export/media" "${PACKAGES_ROOT}/media"
fi

echo "==> AppStream metadata exported to ${PACKAGES}/AppStreamComponents.xml.gz"
echo "==> HTML report is available at ${ASGEN_WORKSPACE}/export/html"

exit 0
