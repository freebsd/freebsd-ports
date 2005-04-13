# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	1.0b1
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gqclient
DISTNAME=	gq-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@oven.org
COMMENT=	GTK-based LDAP client

USE_GMAKE=		yes
USE_ICONV=		yes
USE_GETTEXT=	yes
USE_OPENLDAP=	yes
USE_OPENSSL=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}

OPTIONS=	JPEG	"Enable jpegPhoto attr. handling" On \
		DND	"Enable Drag and drop support in browse mode" On \
		CACHE	"Support the OpenLDAP experimental client cache" On

.include <bsd.port.pre.mk>

.if defined(WITH_JPEG)
USE_GNOME+=	gdkpixbuf
.endif

.if defined(WITH_DND)
CONFIGURE_ARGS+=	--enable-browser-dnd
.endif

.if defined(WITH_CACHE)
CONFIGURE_ARGS+=	--enable-cache
.endif

.include <bsd.port.post.mk>
