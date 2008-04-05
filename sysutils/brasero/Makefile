# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.23 2008/02/06 07:11:46 marcus Exp $

PORTNAME=	brasero
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		totem-plparser.10:${PORTSDIR}/multimedia/totem-pl-parser

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehier nautiluscdburner
USE_GSTREAMER=	gconf core
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify \
		--with-cam
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|blank-cd:|blank-cd;|g' \
		${WRKSRC}/data/brasero.desktop.in.in

.include <bsd.port.mk>
