# New ports collection makefile for:   mozplugger
# Date created:        2 June 2005
# Whom:                Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	mozplugger
PORTVERSION=	1.7.2
CATEGORIES=	www
MASTER_SITES=	http://download.mozdev.org/mozplugger/

MAINTAINER=	lorenl@alzatex.com
COMMENT=	Framework for loading web content in external viewers

EXTRACT_DEPENDS=bzip2:${PORTSDIR}/archivers/bzip2

MAN7=		mozplugger.7

USE_XLIB=	yes
USE_X_PREFIX=	yes

FETCH_CMD=	/usr/bin/fetch -Rr

ALL_TARGET=	freebsd

post-extract:
	${BZIP2_CMD} -d ${WRKSRC}/mozplugger.7.bz2

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
