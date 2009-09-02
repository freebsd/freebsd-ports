# New ports collection makefile for:	aria2fe
# Date created:		12 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aria2fe
DISTVERSION=	0.0.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aria2 QT front-end

RUN_DEPENDS=	aria2c:${PORTSDIR}/www/aria2 \
		xterm:${PORTSDIR}/x11/xterm

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build uic_build moc_build rcc_build
PLIST_FILES=	bin/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src

pre-build:
	@cd ${BUILD_WRKSRC}/&&\
		${SETENV} ${MAKE_ENV} ${QMAKE} -unix ${PORTNAME}.pro

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
