# New ports collection makefile for:	rt3-elixus
# Date created:				5 May 2003
# Whom:					autrijus
#
# $FreeBSD$
#

PORTVERSION=	7387
PORTREVISION=	0
MASTER_SITES=	http://p4.elixus.org/hist/
PKGNAMESUFFIX=	-elixus

COMMENT=	An industrial-grade ticketing system with elixus.org patches

BUILD_DEPENDS=	${SITE_PERL}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable

MASTERDIR=	${.CURDIR}/../../www/rt3
MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
WRKSRC=		${WRKDIR}/rt

.include "${MASTERDIR}/Makefile"
