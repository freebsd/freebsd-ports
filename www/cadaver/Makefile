# New ports collection makefile for: cadaver
# Date created:		13 January 2000
# Whom:			Alex Povolotsky <tarkhil@over.ru>
#
# $FreeBSD$
#

PORTNAME=	cadaver
PORTVERSION=	0.22.0
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/cadaver/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline client for DAV

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		neon.24:${PORTSDIR}/www/neon

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-netrc \
		--with-expat
ALL_TARGET=	cadaver

MAN1=		cadaver.1
PLIST_FILES=	bin/cadaver

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl --with-force-ssl
.endif

.include <bsd.port.mk>
