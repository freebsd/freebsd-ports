# New ports collection makefile for:	libmms
# Date created:				25 Dec 2004
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmms
PORTVERSION=	0.6.2
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for parsing mms:// and mmsh:// type network streams

USE_GNOME=	gnomehack pkgconfig glib20
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.mk>
