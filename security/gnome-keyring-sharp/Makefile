# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	gnome-keyring-sharp
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.go-mono.com/archive/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Fully managed implementation of gnome-keyring

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus \
		${LOCALBASE}/libdata/pkgconfig/gnome-keyring-1.pc:${PORTSDIR}/security/gnome-keyring
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack gtksharp20
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
