# New ports collection makefile for: cadaver
# Date created:		13 January 2000
# Whom:			Alex Povolotsky <tarkhil@over.ru>
#
# $FreeBSD$
#

PORTNAME=	cadaver
PORTVERSION=	0.17.0
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/

MAINTAINER=	tarkhil@over.ru

LIB_DEPENDS=	neon.12:${PORTSDIR}/www/neon

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE} \
		--enable-netrc \
		--with-neon=${LOCALBASE}
ALL_TARGET=	cadaver

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/cadaver.1 ${PREFIX}/man/man1

MAN1=	cadaver.1

.include <bsd.port.mk>
