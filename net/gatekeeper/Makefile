# New ports collection makefile for:	gatekeeper
# Date created:		Wed Apr 15 15:41:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gatekeeper
PORTVERSION=	0.15
CATEGORIES=	net
MASTER_SITES=	http://www.willamowius.de/download/
DISTNAME=	gk015
EXTRACT_SUFX=	.tgz

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/openh323gk

NOCLEANDEPENDS=	yes

USE_NEWGCC=	yes
USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	opt
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/gk ${PREFIX}/bin

.include <bsd.port.mk>
