# New ports collection makefile for:	gcalctool
# Date created:				12 Jun 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/math/gcalctool/Makefile,v 1.9 2006/03/13 23:35:10 mezz Exp $
#

PORTNAME=	gcalctool
PORTVERSION=	5.7.32
PORTEPOCH=	2
CATEGORIES=	math gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\.([0-9]+).*/\1.\2/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 calculator tool based on the old calctool for OpenWindows

USE_BZIP2=	yes
USE_BISON=	yes
INSTALLS_OMF=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gcalctool.1
GCONF_SCHEMAS=	gcalctool.schemas

.include <bsd.port.mk>
