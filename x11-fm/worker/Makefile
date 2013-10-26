# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	worker
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	simond@irrelevant.org
COMMENT=	X11 File Manager based on Directory Opus

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_XORG=	x11
USE_BZIP2=	yes
USE_GCC=	4.6+

USES=	shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor

CFLAGS+=	${PTHREAD_CFLAGS}
OPTIONS_DEFINE=	XFT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFT}
USE_XORG+=	xft
CONFIGURE_ARGS+=	--enable-xft
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
