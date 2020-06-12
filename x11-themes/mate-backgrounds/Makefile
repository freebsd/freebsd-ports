# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-backgrounds
PORTVERSION=	1.24.1
CATEGORIES=	x11-themes graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for MATE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome pathfix tar:xz
USE_GNOME=	glib20 intlhack
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
