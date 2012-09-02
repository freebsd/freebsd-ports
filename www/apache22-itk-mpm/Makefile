# $FreeBSD$
#
# To build this port with the additional mpm-itk-perdir-regex
# patch use -DWITH_ITK_PERDIR_REGEX
#
# To build this port with the additional mpm-itk-limits
# patch use -DWITH_ITK_LIMITS
#
# Note:
# It's not possible to use both patches together
#´
# For a quick description take a look into the mpm-itk* patches
# in the apache22/files directory

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		apache@FreeBSD.org

WITH_MPM=		itk

LATEST_LINK=		apache22-${WITH_MPM}-mpm
DESCR=			${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
