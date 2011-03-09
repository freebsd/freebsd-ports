# New ports collection makefile for:   mozplugger
# Date created:        2 June 2005
# Whom:                Loren M. Lang <loren@north-winds.org>
#
# $FreeBSD$
#

PORTNAME=	mozplugger
PORTVERSION=	1.14.3
CATEGORIES=	www
MASTER_SITES=	http://mozplugger.mozdev.org/files/

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Framework for loading web content in external viewers

USE_XORG=	x11 xt
MAN7=		mozplugger.7
SUB_FILES=	pkg-message
ALL_TARGET=	freebsd
MAKE_ENV=	WEBPLUGINS_DIR="${WEBPLUGINS_DIR}"

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=mozplugger.so

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
