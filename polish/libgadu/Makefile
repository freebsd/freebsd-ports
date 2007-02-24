# New ports collection makefile for:	libgadu
# Date created:		29 December 2005
# Whom:			Aleksander Fafula <alex@BSDGuru.org>
#
# $FreeBSD$

PORTNAME=	libgadu
PORTVERSION=	1.7.0
PORTEPOCH=	1
CATEGORIES=	polish net
MASTER_SITES=	http://toxygen.net/libgadu/files/

MAINTAINER=	alex@BSDGuru.org
COMMENT=	This library is used by many IMs with Gadu-Gadu support

CONFLICTS=	pl-ekg-1.[0-5]* pl-ekg-1.6,2

USE_GMAKE=		yes
USE_GNOME=		gnomehack pkgconfig
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--enable-shared --disable-static --without-openssl

USE_LDCONFIG=		yes

.include <bsd.port.mk>
