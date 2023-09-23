#!/bin/sh

# Creates and updates a git checkout in ${BASE_DIRECTORY} for libkolabxml.
# After that, a new distfile for the ports tree is created.

PROJECT=libkolabxml
BASE_DIRECTORY="$1"
VERSION="$2"

# Remote libkolabxml git repository
REPO="https://git.kolab.org/diffusion/LKX/${PROJECT}.git"
# Local checkout
CHECKOUT="${BASE_DIRECTORY}/${PROJECT}"
# Use the default branch
BRANCH=master

# Make sure we can use ${BASE_DIRECTORY}
if [ ! -d "${BASE_DIRECTORY}" ] || [ ! -w "${BASE_DIRECTORY}" ] ; then
	echo "Directory '${BASE_DIRECTORY}' does not exist"
	exit 1
fi

# Init a new git checkout if it is missing
if [ ! -d "${CHECKOUT}" ] ; then
	git -C "${BASE_DIRECTORY}" clone "${REPO}"
fi

# Update the checkout of the required branch
git -C "${CHECKOUT}" checkout "${BRANCH}" && \
git -C "${CHECKOUT}" pull --ff-only --rebase --autostash && \
git -C "${CHECKOUT}" fetch --tags
if [ $? -ne 0 ] ; then
	echo "Failed to update ${CHECKOUT}"
	exit 1
fi

# Set up information for the distfile
DISTNAME="${PROJECT}-${VERSION}"
DISTFILE="${BASE_DIRECTORY}/${DISTNAME}.tar.xz"

# Tar and compress distfile
git -C ${CHECKOUT} archive --format=tar --prefix="${DISTNAME}/" "${DISTNAME}" | xz > "${DISTFILE}"
if [ $? -ne 0 ] ; then
	echo "Failed to create tarball ${DISTFILE}"
	exit 1
fi

# Print out distfile information
echo -e "Distfile:\t${DISTFILE}"
