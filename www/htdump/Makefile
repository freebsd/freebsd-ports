# Created by: Maxime Henrion (mux@FreeBSD.org)
# $FreeBSD$

PORTNAME=	htdump
PORTVERSION=	0.9x
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://ivo.palli.nl/prog/linux/htdump/bin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to retrieve WWW data

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

CFLAGS+=	${CPPFLAGS}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LFLAGS="-s ${LDFLAGS}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
ALL_TARGET=	ssl
.endif

PLIST_FILES=	bin/htdump

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/htdump ${PREFIX}/bin

.include <bsd.port.mk>
