# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/nautilus-cd-burner/Makefile,v 1.149 2009/09/25 18:40:01 kwm Exp $

PORTNAME=	nautilus-cd-burner
PORTVERSION=	2.24.0
PORTREVISION=	8
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD burner view for Nautilus

DEPRECATED=	nautilus will be updated to the 3.x version which is not compatible with 2.x
EXPIRATION_DATE=2014-04-10

BUILD_DEPENDS=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
RUN_DEPENDS=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

CONFIGURE_ARGS=	--enable-gnome-mount
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2 ltverhack \
		desktopfileutils ltasneededhack eel2 libgnomeui
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	nautilus-cd-burner.schemas

OPTIONS_DEFINE=	DVD
OPTIONS_DEFAULT=DVD
DVD_DESC=	DVD support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVD}
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib/g.*\.h>|glib.h>|g' \
		${WRKSRC}/src/nautilus-burn.h \
		${WRKSRC}/src/nautilus-burn-init.h \
		${WRKSRC}/src/nautilus-cd-burner.h

post-install:
	-@update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
