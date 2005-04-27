# Ports collection makefile for:  htdump
# Date created:                   Tue Feb 20, 2001
# Whom:                           Maxime Henrion (mux@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	htdump
PORTVERSION=	0.9x
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ivo.palli.nl/prog/linux/htdump/bin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to retrieve WWW data

OPTIONS=	SSL "SSL support" on

USE_GETOPT_LONG=yes
CFLAGS+=	${CPPFLAGS}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LFLAGS="-s ${LDFLAGS}"

.include <bsd.port.pre.mk>

.if defined(WITH_SSL)
USE_OPENSSL=	yes
ALL_TARGET=	ssl
.endif

PLIST_FILES=	bin/htdump

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htdump ${PREFIX}/bin

.include <bsd.port.post.mk>
