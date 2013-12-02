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
USES=		gmake
MAN7=		mozplugger.7
SUB_FILES=	pkg-message

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=mozplugger.so
MAKE_ENV=	WEBPLUGINS_DIR="${WEBPLUGINS_DIR}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	@${REINPLACE_CMD} -e 's|"/etc|"${PREFIX}/etc|g' \
		${WRKSRC}/mozplugger.c

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
