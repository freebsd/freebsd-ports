# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	worker
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	simond@irrelevant.org
COMMENT=	X11 File Manager based on Directory Opus

LICENSE=	GPLv2

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_BZIP2=	yes
USE_GCC=	yes

USES=	shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor

CFLAGS+=	${PTHREAD_CFLAGS}

OPTIONS_DEFINE=	XFT

XFT_CONFIGURE_ENABLE=	xft
XFT_USE=	XORG=xft

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
