# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	1.3.4
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}client/GQ%20Unstable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based LDAP client

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

OPTIONS=	DND	"Enable Drag and drop support in browse mode" On \
		CACHE	"Support the OpenLDAP experimental client cache" On

USE_GNOME=	gnometarget libglade2 gnomedocutils
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DND)
CONFIGURE_ARGS+=	--enable-browser-dnd
.endif

.if !defined(WITHOUT_CACHE)
CONFIGURE_ARGS+=	--enable-cache
.endif

.include <bsd.port.post.mk>
