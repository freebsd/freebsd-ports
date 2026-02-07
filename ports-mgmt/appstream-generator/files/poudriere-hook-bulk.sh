#!/bin/sh
# /usr/local/etc/poudriere.d/hooks/bulk.sh

status="$1"
shift

if [ "$status" != "done" ]; then
	exit 0
fi

ASGEN_CMD=/usr/local/bin/appstream-generator
# The location for the generated data
# This should be persistent across "poudriere bulk" runs and be specific to
# the given jail-ports-set combination (i.e. have ${MASTERNAME} in the path)
ASGEN_WORKSPACE=/asgen/${MASTERNAME}
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
"MediaBaseUrl": "${REPOSITORY_URL}/${ABI}/media"
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

# Copy the metadata archive back to Poudriere repository root
cp "${ASGEN_WORKSPACE}/export/data/${suite}/default/Components-${ARCH}.xml.gz" "${PACKAGES}/AppStreamComponents.xml.gz"

# Link media files
ln -s "${ASGEN_WORKSPACE}/export/media" "${PACKAGES}/media"

# Make a symlink to follow Poudriere layout
if [ "$(basename ${PACKAGES})" == ".latest" ]; then
	ln -fs .latest/AppStreamComponents.xml.gz ${PACKAGES}/../AppStreamComponents.xml.gz
fi

exit 0
