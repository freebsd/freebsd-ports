# New ports collection makefile for:	libgadu
# Date created:		29 December 2005
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$

PORTNAME=	libgadu
PORTVERSION=	20051229
PORTREVISION=	2
CATEGORIES=	polish net
MASTER_SITES=	http://bsdguru.org/distfiles/

MAINTAINER=	alex@BSDGuru.org
COMMENT=	This library is used by many IMs with Gadu-Gadu support

CONFLICTS=	pl-ekg-1.[0-5]* pl-ekg-1.6,2

USE_GMAKE=		yes
USE_GNOME=		gnomehack pkgconfig
USE_AUTOTOOLS=		aclocal:15 autoheader:259 autoconf:259
ACLOCAL_ARGS=		-I ${WRKSRC}/m4

CONFIGURE_ARGS=		--enable-shared --disable-static --without-openssl

INSTALLS_SHLIB=		yes

.include <bsd.port.mk>
