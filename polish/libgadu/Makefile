# New ports collection makefile for:	libgadu
# Date created:		29 December 2005
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$

PORTNAME=	libgadu
DISTVERSION=	1.10.1
PORTEPOCH=	1
CATEGORIES=	polish net
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	mwisnicki+freebsd@gmail.com
COMMENT=	This library is used by many IMs with Gadu-Gadu support

LICENSE=	LGPL21

CONFLICTS=	pl-ekg-1.[0-6]*

USE_GNOME=		gnomehack pkgconfig
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--enable-shared --disable-static --with-pthread \
			--disable-tests --without-gnutls

USE_LDCONFIG=		yes

OPTIONS=	OPENSSL "Build with OpenSSL support" on

PLIST_FILES=	include/libgadu.h \
		lib/libgadu.la \
		lib/libgadu.so \
		lib/libgadu.so.3 \
		libdata/pkgconfig/libgadu.pc

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

post-patch:
	@${REINPLACE_CMD} -Ee 's/@SUBDIRS_DOXYGEN@//' ${WRKSRC}/Makefile.in

pre-install:
# OpenSSL from base system lacks .pc file for pkgconfig
.if defined(WITH_OPENSSL)
	@${REINPLACE_CMD} -e 's|openssl| |g' ${WRKSRC}/pkgconfig/libgadu.pc
.endif

.include <bsd.port.post.mk>
