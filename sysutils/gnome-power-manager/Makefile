# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/sysutils/gnome-power-manager/Makefile,v 1.5 2009/04/19 06:23:37 marcus Exp $
#

PORTNAME=	gnome-power-manager
PORTVERSION=	2.24.4
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

BUILD_DEPENDS=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
    		${LOCALBASE}/share/sgml/docbook/4.1/catalog:${PORTSDIR}/textproc/docbook-410
LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		notify.1:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		polkit-gnome.0:${PORTSDIR}/sysutils/policykit-gnome \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:22
USE_GSTREAMER=	good
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libwnck \
		gnomedocutils gnomepanel
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--enable-policykit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-power-manager.schemas

MAN1=		gnome-power-manager.1 gnome-power-preferences.1 \
		gnome-power-statistics.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv|| ; s|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
