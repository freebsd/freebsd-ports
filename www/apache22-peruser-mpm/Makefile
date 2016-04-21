# $FreeBSD$

# Apache 2.2.X with peruser mpm 0.3.0-dc3
# Peruser main url:		http://telana.com/peruser.php
# Peruser patches:		http://source.kood.ee/
# This port contains the main patch, including the dc3 patch

MASTERDIR=		${.CURDIR}/../apache22

MAINTAINER=		ports@FreeBSD.org

WITH_MPM=		peruser

DESCR=			${.CURDIR}/pkg-descr

EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0.patch
EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0-dc3.patch
EXTRA_PATCHES+=		${.CURDIR}/files/httpd-2.2.3-peruser-0.3.0-dc3-r57.patch

BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
