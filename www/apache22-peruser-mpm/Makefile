# New ports collection makefile for:	apache22-peruser-mpm
# Apache 2.2.X with peruser mpm 0.3.0-dc3
# Date created:                 13 Sep 2008
# Whom:                         Jille Timmermans <jille@quis.cx>
# Peruser main url:		http://telana.com/peruser.php
# Peruser patches:		http://source.kood.ee/
# This port contains the main patch, including the dc3 patch
#
# $FreeBSD$
#

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		jille@quis.cx

WITH_MPM=		peruser

LATEST_LINK=		apache22-${WITH_MPM:L}-mpm
DESCR=			${.CURDIR}/pkg-descr

EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0.patch
EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0-dc3.patch
EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0-dc3-r57.patch

.include "${MASTERDIR}/Makefile"
