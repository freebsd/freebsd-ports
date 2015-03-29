# $FreeBSD$

PORTNAME=	vimb
PORTVERSION=	2.9
CATEGORIES=	www
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Vim like browser

LICENSE=	GPLv3

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2

CONFLICTS_INSTALL=	vimb-gtk3-*

USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_TAGNAME=	cd61814
PLIST_FILES=	bin/vimb man/man1/vimb.1.gz

MAKE_ENV=	GTK="2"
USES=		gmake pkgconfig
USE_GNOME=	gtk20

post-extract:
	${MV}	${WRKSRC}/src/config.def.h ${WRKSRC}/src/config.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vimb.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/vimb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
