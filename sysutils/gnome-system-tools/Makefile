# New ports collection makefile for:	gnomesystemtools
# Date created:				17 May 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/gnome-system-tools/Makefile,v 1.59 2007/03/12 12:55:31 ahze Exp $

PORTNAME=	gnome-system-tools
PORTVERSION=	2.18.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-system-tools/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-system-tools-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to configure workstations

LIB_DEPENDS=	oobs-1.3:${PORTSDIR}/devel/liboobs

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_XLIB=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack nautilus2
USE_AUTOTOOLS=	libtool:15
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-services
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-system-tools.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|$${prefix}/$${DATADIRNAME}|$${datadir}|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
