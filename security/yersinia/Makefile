# Created by: se
# $FreeBSD$

PORTNAME=	yersinia
PORTVERSION=	0.8.2
CATEGORIES=	security
# MASTER_SITES=	http://www.yersinia.net/download/

MAINTAINER=	ayu@commun.jp
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:net/libnet \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gnome ncurses pkgconfig
USE_GNOME+=	cairo gdkpixbuf2 gtk20 
PKGNAMESUFFIX=	-gtk
USE_GITHUB=	yes
GH_TUPLE=	tomac:yersinia:8c0d7c5
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/yersinia \
		man/man8/yersinia.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
