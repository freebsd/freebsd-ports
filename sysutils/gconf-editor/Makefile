# New ports collection makefile for:	gconf-editor
# Date created:				12 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gconf-editor/Makefile,v 1.82 2010/04/01 15:48:36 kwm Exp $
#

PORTNAME=	gconf-editor
PORTVERSION=	2.30.0
PORTEPOCH=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A gconf database editor for the GNOME 2 environment

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gconf-editor.1
GCONF_SCHEMAS=	gconf-editor.schemas

.include <bsd.port.mk>
