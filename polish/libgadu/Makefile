# New ports collection makefile for:	libgadu
# Date created:		29 December 2005
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$

PORTNAME=	libgadu
PORTVERSION=	1.8.0
PORTEPOCH=	1
CATEGORIES=	polish net
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	alex@BSDGuru.org
COMMENT=	This library is used by many IMs with Gadu-Gadu support

CONFLICTS=	pl-ekg-1.[0-6]*

USE_GMAKE=		yes
USE_GNOME=		gnomehack pkgconfig
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--enable-shared --disable-static

USE_LDCONFIG=		yes

PLIST_FILES=	include/libgadu.h \
		lib/libgadu.la \
		lib/libgadu.so \
		lib/libgadu.so.3 \
		libdata/pkgconfig/libgadu.pc

OPTIONS=	OPENSSL "Build with OPENSSL support" on

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=	--without-openssl
.endif

.include <bsd.port.mk>
