# New ports collection makefile for:	gnome-keyring-sharp
# Date created:		2008-10-08
# Whom:			Romain Tartiere <romain@blogreen.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-keyring-sharp
PORTVERSION=	1.0.2
CATEGORIES=	security
MASTER_SITES=	http://www.go-mono.com/archive/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Fully managed implementation of gnome-keyring

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-1.pc:${PORTSDIR}/security/gnome-keyring
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gtksharp20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
