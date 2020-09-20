# $FreeBSD$

PORTNAME=	libnpupnp
DISTVERSION=	4.0.11
CATEGORIES=	net
MASTER_SITES=	https://www.lesbonscomptes.com/upmpdcli/downloads/

PATCH_SITES=	https://framagit.org/medoc92/npupnp/commit/
PATCHFILES=	9898d0381b6ab625251e68d26c7c85befc9b9177.patch:-p1

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

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/libnpupnp.la

.include <bsd.port.mk>
