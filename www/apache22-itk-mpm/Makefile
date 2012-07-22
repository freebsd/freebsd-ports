# New ports collection makefile for:	apache22-itk-mpm
# Date created:				2010-11-5
# Whom:					Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$
#
# To build this port with the additional mpm-itk-perdir-regex
# patch use -DWITH_ITK_PERDIR_REGEX
#
# For a quick description take a look into the mpm-itk* patches
# in the apache22/files directory

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		apache@FreeBSD.org

WITH_MPM=		itk

LATEST_LINK=		apache22-${WITH_MPM:L}-mpm
DESCR=			${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
