# New ports collection makefile for:	glibwww
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glibwww
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/glibwww/0.2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A library for people wanting to use libwww with gtk/gnome

LIB_DEPENDS=	wwwzip.1:${PORTSDIR}/www/libwww

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
