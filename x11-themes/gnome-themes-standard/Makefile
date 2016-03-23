# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-themes-standard
PORTVERSION=	3.18.0
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Standard themes for GNOME

CONFLICTS=	gnome-themes-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		gettext-tools gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gtk20 gtk30 intlhack librsvg2
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|install: install-data|install:|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
