# New ports collection makefile for:	gossip
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gossip
PORTVERSION=	0.10
CATEGORIES=	net-im gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.10

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK2 Jabber Instant Messaging client

LIB_DEPENDS=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gossip.schemas

.include <bsd.port.mk>
