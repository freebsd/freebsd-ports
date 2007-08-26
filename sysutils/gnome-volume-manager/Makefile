# New ports collection makefile for:	gnome-volume-manager
# Date created:			02 May 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-volume-manager/Makefile,v 1.13 2007/03/09 22:15:17 mezz Exp $
#

PORTNAME=	gnome-volume-manager
PORTVERSION=	2.17.0
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Automatically mount removable media, and more

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.1:${PORTSDIR}/devel/libnotify

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-multiuser
GCONF_SCHEMAS=	gnome-volume-manager.schemas

.include <bsd.port.mk>
