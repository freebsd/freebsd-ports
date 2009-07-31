# New ports collection makefile for:	gdl
# Date created:				24 July 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gdl/Makefile,v 1.22 2009/03/17 18:08:56 kwm Exp $
#

PORTNAME=	gdl
PORTVERSION=	2.26.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
