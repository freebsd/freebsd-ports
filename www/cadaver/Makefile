# New ports collection makefile for: cadaver
# Date created:		13 January 2000
# Whom:			Alex Povolotsky <tarkhil@over.ru>
#
# $FreeBSD$
#

PORTNAME=	cadaver
PORTVERSION=	0.20.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		expat.4:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_ARGS=	--enable-netrc \
		--with-included-neon \
		--with-expat
ALL_TARGET=	cadaver

MAN1=	cadaver.1

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl --with-force-ssl
.endif

.include <bsd.port.mk>
