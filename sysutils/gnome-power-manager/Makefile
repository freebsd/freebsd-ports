# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager/Makefile,v 1.73 2011/04/30 20:43:26 mezz Exp $

PORTNAME=	gnome-power-manager
PORTVERSION=	2.32.0
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	upower-glib.1:${PORTSDIR}/sysutils/upower \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra \
		notify.4:${PORTSDIR}/devel/libnotify \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit

CONFLICTS=	gnome-power-manager-3.[0-9]*

USES=		gettext gmake pkgconfig
USE_BZIP2=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack intlhack libwnck \
		gnomedocutils gnomepanel
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--enable-hal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
