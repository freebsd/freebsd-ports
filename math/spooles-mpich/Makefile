# New ports collection makefile for:	spooles-mpich
# Date created:         5 May 2003
# Whom:                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

MASTERDIR=      ${.CURDIR}/../spooles/
USE_MPI=	YES

.include "${.CURDIR}/../spooles/Makefile"

PKGNAMESUFFIX=  -mpich

BUILD_DEPENDS=  ${LOCALBASE}/mpich/lib/libmpich.a:${PORTSDIR}/net/mpich
