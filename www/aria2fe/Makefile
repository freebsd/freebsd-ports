# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aria2fe
DISTVERSION=	0.0.5
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Aria2 Qt front-end

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	aria2c:${PORTSDIR}/www/aria2 \
		xterm:${PORTSDIR}/x11/xterm

USES=		tar:bzip2 qmake
USE_QT4=	gui moc_build rcc_build uic_build

PLIST_FILES=	bin/${PORTNAME}

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
