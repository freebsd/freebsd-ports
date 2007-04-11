# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager/Makefile,v 1.23 2007/03/13 00:33:21 mezz Exp $
#

PORTNAME=	gnome-power-manager
PORTVERSION=	2.18.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

BUILD_DEPENDS=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
    		${LOCALBASE}/share/sgml/docbook/4.1/catalog:${PORTSDIR}/textproc/docbook-410
LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.1:${PORTSDIR}/devel/libnotify

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libwnck \
		gnomedocutils gnomepanel
CONFIGURE_ARGS=	--disable-icon-framing \
		--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-power-manager.schemas

MAN1=		gnome-power-manager.1 gnome-power-preferences.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv|| ; s|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
