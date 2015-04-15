# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=	worker
PORTVERSION=	3.6.2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/

MAINTAINER=	mp39590@gmail.com
COMMENT=	X11 File Manager based on Directory Opus

LICENSE=	GPLv2

RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_XORG=	x11

USES=	shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor

OPTIONS_DEFINE=	XFT AVFS

AVFS_DESC=	Use AVFS library to access an archives
AVFS_LIB_DEPENDS=	libavfs.so:${PORTSDIR}/sysutils/avfs
XFT_CONFIGURE_ENABLE=	xft
XFT_USE=	XORG=xft

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>
