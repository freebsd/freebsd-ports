# $FreeBSD$

# To build this port with the additional mpm-itk-perdir-regex
# patch use -DWITH_ITK_PERDIR_REGEX
#
# To build this port with the additional mpm-itk-limits
# patch use -DWITH_ITK_LIMITS
#
# Note:
# It's not possible to use both patches together
#
# For a quick description take a look into the mpm-itk* patches
# in the files directory

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		apache@FreeBSD.org

WITH_MPM=		itk

LATEST_LINK=		apache22-${WITH_MPM}-mpm
DESCR=			${.CURDIR}/pkg-descr

MPM_ITK_VERSION?=	20110321-01

EXTRA_PATCHES+=		${.CURDIR}/files/mpm-itk-${MPM_ITK_VERSION}

.if defined (WITH_ITK_PERDIR_REGEX) && defined (WITH_ITK_LIMITS)
IGNORE=	use only one patch option not both (WITH_ITK_PERDIR_REGEX or WITH_ITK_LIMITS)
.endif

.if defined (WITH_ITK_PERDIR_REGEX)
EXTRA_PATCHES+=		${.CURDIR}/files/mpm-itk-perdir-regex
.endif

.if defined (WITH_ITK_LIMITS)
EXTRA_PATCHES+=		${.CURDIR}/files/mpm-itk-limits
.endif

.include "${MASTERDIR}/Makefile"
