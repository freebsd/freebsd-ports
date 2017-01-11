# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-pty-helper
PORTVERSION=	0.40.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME/sources/vte/${PORTVERSION:R}
DISTNAME=	vte-${PORTVERSION}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	utmp/wtmp/lastlog helper program for the vte Terminal widget

BUILD_DEPENDS+=	gnutls>=0:security/gnutls

PORTSCOUT=	ignore:1

USES=		gmake tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CONFIGURE_WRKSRC=	${WRKSRC}/gnome-pty-helper
BUILD_WRKSRC=	${WRKSRC}/gnome-pty-helper
INSTALL_WRKSRC=	${WRKSRC}/gnome-pty-helper

post-patch:
	@${REINPLACE_CMD} -e 's|(AM_MAKEFLAGS) install-exec-hook|(AM_MAKEFLAGS)|g' \
		${WRKSRC}/gnome-pty-helper/Makefile.in

.include <bsd.port.mk>
