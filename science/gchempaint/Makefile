# New ports collection makefile for:	gchempaint
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchempaint
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	2D chemical structures editor for GNOME 2

BUILD_DEPENDS=	gnome-doc-prepare:${PORTSDIR}/textproc/gnomedocutils
LIB_DEPENDS=	gcu.6:${PORTSDIR}/science/gchemutils

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
GCONF_SCHEMAS=	gchempaint-arrows.schemas
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeprintui libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-help-dir=${PREFIX}/share/gnome/help

.include <bsd.port.mk>
