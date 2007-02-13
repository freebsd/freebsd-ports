# New ports collection makefile for:	gq
# Date Created:				8 Jun 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	gq
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	gqclient
DISTNAME=	gq-${PORTVERSION:S/r/rc/}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	GTK-based LDAP client

LIB_DEPENDS=	gnome-keyring:${PORTSDIR}/security/gnome-keyring

USE_GCC=	3.4+
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_OPENLDAP=	yes
USE_OPENSSL=	yes
USE_XLIB=	yes
USE_GNOME=	gnomehier gtk20 libxml2 libglade2 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}

OPTIONS=	JPEG	"Enable jpegPhoto attr. handling" On \
		DND	"Enable Drag and drop support in browse mode" On \
		CACHE	"Support the OpenLDAP experimental client cache" On

CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
	       	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

.if !defined(WITHOUT_JPEG)
USE_GNOME+=	gdkpixbuf
.endif

.if !defined(WITHOUT_DND)
CONFIGURE_ARGS+=	--enable-browser-dnd
.endif

.if !defined(WITHOUT_CACHE)
CONFIGURE_ARGS+=	--enable-cache
.endif

.include <bsd.port.post.mk>
