# New ports collection makefile for:	x11-fm/pcmanfm
# Date created:				27 March 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $Carpetsmoker: ports/x11-fm/pcmanfm/Makefile,v 1.2 2008/04/06 20:25:05 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	pcmanfm
PORTVERSION=	0.9.7
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM2%20%2B%20Libfm%20%28experimental%29/PCManFM/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PCMan File Manager

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		fm-gtk.0:${PORTSDIR}/x11/libfm

USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_FAM=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

OPTIONS=	NLS "Native Language Support (devel/gettext)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
