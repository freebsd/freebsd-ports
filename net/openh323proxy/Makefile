# New ports collection makefile for:	openh323proxy
# Date created:		Tue Nov 21 12:59:00 GMT 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openh323proxy
PORTVERSION=	0.9.12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/opengate_proxy ${PREFIX}/bin

.include <bsd.port.mk>
