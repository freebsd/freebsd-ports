# New ports collection makefile for:	gatekeeper
# Date created:		Wed Apr 15 15:41:00 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gatekeeper
PORTVERSION=	0.12p
CATEGORIES=	net
MASTER_SITES=	http://www.willamowius.de/download/
DISTNAME=	gk012pre

MAINTAINER=	roger@freebsd.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/gk

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR= ${WRKDIRPREFIX}${PORTSDIR}/net/openh323/work/pwlib \
		OPENH323DIR= ${WRKDIRPREFIX}${PORTSDIR}/net/openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/gk ${PREFIX}/bin

.include <bsd.port.mk>
