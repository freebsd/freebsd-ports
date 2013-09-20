# Created by: Gaspar Chilingarov <nm@web.am>
# $FreeBSD$

PORTNAME=	mountapp
PORTVERSION=	3.0
PORTREVISION=	9
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	SF

MAINTAINER=	nm@web.am
COMMENT=	Windowmaker application, Resembles wmmount with extra functionality

BUILD_DEPENDS=	${LOCALBASE}/lib/libWINGs.a:${PORTSDIR}/x11-wm/windowmaker

USES=		gettext
USE_GNOME=	gtk12 glib12

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib -lintl

NO_STAGE=	yes
.include <bsd.port.mk>
