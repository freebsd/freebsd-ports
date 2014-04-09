# Created by: Loren M. Lang <loren@north-winds.org>
# $FreeBSD$

PORTNAME=	mozplugger
PORTVERSION=	2.1.4
CATEGORIES=	www
MASTER_SITES=	http://mozplugger.mozdev.org/files/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Framework for loading web content in external viewers

GNU_CONFIGURE=	yes
USE_XORG=	x11 xt
USES=		desthack gmake webplugin:native
SUB_FILES=	pkg-message

WEBPLUGIN_FILES=mozplugger.so
MAKE_ENV=	WEBPLUGINS_DIR="${WEBPLUGIN_DIR}"
MAKE_ARGS=	root=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' \
		${WRKSRC}/mozplugger.c

.include <bsd.port.mk>
