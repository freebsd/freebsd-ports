# New ports collection makefile for:	gchempaint
# Date created:			Mar 18, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	gchempaint
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://jean.brefort.free.fr/info/gcp/download/
MASTER_SITE_SUBDIR=	${PORTNAME}/unstable.pkg/${PORTVERSION}

MAINTAINER=	pav@FreeBSD.org
COMMENT=	2D chemical structures editor for GNOME 2

LIB_DEPENDS=	gcu.2:${PORTSDIR}/science/gchemutils

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeprintui libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
