# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager/Makefile,v 1.63 2010/04/26 17:38:05 kwm Exp $
#

PORTNAME=	gnome-power-manager
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		devkit-power-gobject.1:${PORTSDIR}/sysutils/upower \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		notify.1:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui libwnck \
		gnomedocutils gnomepanel
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--enable-hal
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-power-manager.schemas

.if !defined(NO_INSTALL_MANPAGES)
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
MAN1=		gnome-power-manager.1 gnome-power-preferences.1 \
		gnome-power-statistics.1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv|| ; s|-Werror||g' \
		${WRKSRC}/configure
.if defined(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} -e "s|2MAN_TRUE=$$|2MAN_TRUE='#'|g ; \
		s|2MAN_FALSE='#'|2MAN_FALSE=|g" ${WRKSRC}/configure
.endif

.include <bsd.port.mk>
