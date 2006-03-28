# New ports collection makefile for:	gossip
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gossip
PORTVERSION=	0.10.2
CATEGORIES=	net-im gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.10

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK2 Jabber Instant Messaging client

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth \
		dbus-1.2:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui gnomedocutils
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--enable-dbus=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gossip.schemas

OPTIONS=	NOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=		notify.1:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=	--enable-libnotify=no
.endif

.include <bsd.port.post.mk>
