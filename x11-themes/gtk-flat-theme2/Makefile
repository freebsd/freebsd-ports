# Created by: Philip Paeps <philip@paeps.cx>
# $FreeBSD$

PORTNAME=	gtk-flat-theme2
PORTVERSION=	0.1
PORTREVISION=	13
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	gtk2flat
DISTNAME=	gtk2flat-default

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A port of the Flat GTK+ engine to GTK+ 2.0

WRKSRC=		${WRKDIR}/gtk-flat-theme-2.0

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomehack gtk20

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
