# New ports collection makefile for:	glibwww
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glibwww
PORTVERSION=	0.2
PORTREVISION=	7
CATEGORIES=	www gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for people wanting to use libwww with gtk/gnome

LIB_DEPENDS=	wwwzip.1:${PORTSDIR}/www/libwww

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_GNOME=	gnomelibs
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
