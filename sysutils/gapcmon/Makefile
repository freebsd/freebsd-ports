# $FreeBSD$

PORTNAME=	gapcmon
PORTVERSION=	0.8.9
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Monitor apcupsd with GTK+2 GUI

LICENSE=	GPLv2

SUB_FILES=	pkg-message
USE_GNOME=	gconf2
USES=		pkgconfig gmake tar:bzip2
USE_XORG=	x11
GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib -lX11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
