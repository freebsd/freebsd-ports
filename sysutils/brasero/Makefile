# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.34 2009/01/09 22:03:01 kwm Exp $

PORTNAME=	brasero
PORTVERSION=	0.8.4
PORTREVISION=	3
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		totem-plparser.12:${PORTSDIR}/multimedia/totem-pl-parser

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier nautiluscdburner
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

.include <bsd.port.mk>
