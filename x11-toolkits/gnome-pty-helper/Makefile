PORTNAME=	gnome-pty-helper
PORTVERSION=	0.40.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DISTNAME=	vte-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	utmp/wtmp/lastlog helper program for the vte Terminal widget
WWW=		https://gitlab.gnome.org/GNOME/vte

LICENSE=	LGPL21

BUILD_DEPENDS+=	gnutls>=0:security/gnutls

USES=		gmake tar:xz
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	ignore:1

BUILD_WRKSRC=	${WRKSRC}/gnome-pty-helper
CONFIGURE_WRKSRC=	${WRKSRC}/gnome-pty-helper
INSTALL_WRKSRC=	${WRKSRC}/gnome-pty-helper

post-patch:
	@${REINPLACE_CMD} -e 's|(AM_MAKEFLAGS) install-exec-hook|(AM_MAKEFLAGS)|g' \
		${WRKSRC}/gnome-pty-helper/Makefile.in

.include <bsd.port.mk>
