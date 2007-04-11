# New ports collection makefile for:	nautilus-cd-burner
# Date created:				13 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/nautilus-cd-burner/Makefile,v 1.128 2007/03/12 20:33:36 mezz Exp $
#

PORTNAME=	nautilus-cd-burner
PORTVERSION=	2.18.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD burner view for Nautilus

RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack nautilus2 ltverhack \
		desktopfileutils
USE_CDRTOOLS=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	nautilus-cd-burner.schemas

OPTIONS=	DVD "Enable DVD support" on \
		CJK "Use cdrtools-cjk instead of cdrtools" off \
		GNOMEMOUNT "Enable sysutils/gnome-mount support" off

.include <bsd.port.pre.mk>

.if defined(WITH_CJK)
WITHOUT_DVD=	yes
.endif

.if !defined(WITHOUT_DVD)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.if defined(WITH_GNOMEMOUNT)
BUILD_DEPENDS+=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
RUN_DEPENDS+=	gnome-mount:${PORTSDIR}/sysutils/gnome-mount
CONFIGURE_ARGS+=	--enable-gnome-mount
.else
CONFIGURE_ARGS+=	--disable-gnome-mount
.endif

post-install:
	-@update-desktop-database
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
