# New ports collection makefile for:	amyc
# Date Created:				10 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	amyc
PORTVERSION=	0.9.159
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.crevola.com/about/current/

MAINTAINER=	petef@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

USE_GNOMENG=	yes
USE_GNOME=	gnomehack
WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
PLIST_SUB=	WITH_GTK=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
.else
PLIST_SUB=	WITH_GTK="@comment "
.endif

.include <bsd.port.post.mk>
