# New ports collection makefile for:	grdc-applet
# Date created:				12 April 2009
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	remmina
PORTVERSION=	0.7.0
CATEGORIES=	net gnome
MASTER_SITES=	SF/${PORTNAME}/0.7/
PKGNAMESUFFIX=	-applet
DISTNAME=	${PORTNAME}-gnome-${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A GNOME Desktop applet for Remmina

RUN_DEPENDS=	remmina:${PORTSDIR}/net/remmina

OPTIONS=	AVAHI	"Build with Avahi support"	off

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 gnomepanel
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_AVAHI)
LIB_DEPENDS+=	avahi-ui.0:${PORTSDIR}/net/avahi-gtk
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

.include <bsd.port.post.mk>
