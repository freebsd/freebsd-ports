# New ports collection makefile for:	libgadu
# Date created:		29 December 2005
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$

PORTNAME=	libgadu
PORTVERSION=	20051229
PORTREVISION=	1
CATEGORIES=	polish net
MASTER_SITES=	http://bsdguru.org/distfiles/

MAINTAINER=	alex@BSDGuru.org
COMMENT=	This library is used by many IMs with Gadu-Gadu support

USE_GMAKE=		yes
USE_GNOME=		gnomehack pkgconfig
USE_AUTOTOOLS=		aclocal:15 autoheader:259 autoconf:259
ACLOCAL_ARGS=		-I ${WRKSRC}/m4

CONFIGURE_ARGS=		--enable-shared --disable-static --without-openssl

INSTALLS_SHLIB=		yes

post-install:
	${RM} ${PREFIX}/lib/libgadu.so ${PREFIX}/lib/libgadu.so.3
	${MV} ${PREFIX}/lib/libgadu.so.3.3 ${PREFIX}/lib/libgadu.so.3
	${LN} -s ${PREFIX}/lib/libgadu.so.3 ${PREFIX}/lib/libgadu.so

.include <bsd.port.mk>
