# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	1.0b1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gqclient
DISTNAME=	gq-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@oven.org
COMMENT=	GTK-based LDAP client

.if !defined(WITHOUT_JPEG)
USE_GNOME=	gdkpixbuf
.endif

USE_GMAKE=		yes
USE_ICONV=		yes
USE_GETTEXT=	yes
USE_OPENLDAP=	yes
USE_OPENSSL=	yes
USE_X_PREFIX=	yes
USE_GNOME+=	gtk20 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap=${LOCALBASE}

.if defined(WITH_DND)
CONFIGURE_ARGS+=	--enable-browser-dnd
.endif

.if defined(WITH_CACHE)
CONFIGURE_ARGS+=	--enable-cache
.endif

post-extract:
	@${ECHO_MSG} "This port supports the following configuration knobs:"
	@${ECHO_MSG} "WITHOUT_JPEG=yes  Disable jpegPhoto attr. handling"
	@${ECHO_MSG} "WITH_DND=yes      Enable Drag and drop support in browse mode"
	@${ECHO_MSG} "WITH_CACHE=yes    Support the OpenLDAP experimental client cache"
	@${ECHO_MSG}

.include <bsd.port.mk>
