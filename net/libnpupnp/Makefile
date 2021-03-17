# $FreeBSD$

PORTNAME=	libnpupnp
DISTVERSION=	4.1.1
CATEGORIES=	net
MASTER_SITES=	https://www.lesbonscomptes.com/upmpdcli/downloads/

MAINTAINER=	daniel.engberg.lists@pyret.net
COMMENT=	C++ base UPnP library, derived from Portable UPnP, a.k.a libupnp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libmicrohttpd.so:www/libmicrohttpd

USES=		autoreconf compiler:c++11-lang libtool localbase pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
