# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-calc
PORTVERSION=	1.22.2
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE calculator tool based on the old calctool for OpenWindows

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pkgconfig tar:xz
USE_GNOME=	cairo gdkpixbuf2 gtk30 intlhack libxml2
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.mate.calc.gschema.xml

.include <bsd.port.mk>
