# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.11 2006/09/08 00:44:18 ahze Exp $

PORTNAME=	brasero
PORTVERSION=	0.4.90
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	bonfire

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.2:${PORTSDIR}/devel/libnotify \
		totem-plparser.1:${PORTSDIR}/multimedia/totem-gstreamer

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehier nautiluscdburner
USE_GSTREAMER=	gconf core
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

.include <bsd.port.mk>
