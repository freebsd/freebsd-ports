# New ports collection makefile for:	cphone
# Date created:		Thu May 24 15:50:00 BST 2000
# Whom:			Roger Hardiman <roger@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cphone
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/cphone/
DISTNAME=	cphone_0.1.0

MAINTAINER=	roger@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/net/openh323:build

WRKSRC=		${WRKDIR}/${PORTNAME}

NOCLEANDEPENDS=	yes

USE_BISON=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
ALL_TARGET=	optnoshared
MAKE_ENV=	QTDIR=${X11BASE} \
		PWLIBDIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${.CURDIR}/../openh323/work/openh323
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj_${OPSYS}_${THE_MACHTYPE}_r/cphone ${PREFIX}/bin

.include <bsd.port.mk>
