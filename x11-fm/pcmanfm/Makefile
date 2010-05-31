# New ports collection makefile for:	x11-fm/pcmanfm
# Date created:				27 March 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/x11-fm/pcmanfm/Makefile,v 1.2 2008/04/06 20:25:05 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	pcmanfm
PORTVERSION=	0.5.2
PORTREVISION=	3
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/PCManFM%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PCMan File Manager

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_FAM=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--disable-desktop-integration \
		--disable-hal

OPTIONS=	NLS "Native Language Support (devel/gettext)" on
#		HAL "Enable auto-mounthing with HAL (sysutils/hal and devel/dbus)" on
# Disable HAL for now, it doesn't seem to work very well in this version

.include <bsd.port.pre.mk>

#.if !defined(WITHOUT_HAL)
#LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal \
#		dbus-1.3:${PORTSDIR}/devel/dbus
#CONFIGURE_ARGS+=--enable-hal
#PLIST_SUB+=	HAL=""
#.else
#CONFIGURE_ARGS+=--disable-hal
#PLIST_SUB+=	HAL="@comment"
#.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
