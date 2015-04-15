# $FreeBSD$

PORTNAME=	vimb
PORTVERSION=	2.9
CATEGORIES=	www
PKGNAMESUFFIX=	-gtk3

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Vim like browser

LICENSE=	GPLv3

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3

CONFLICTS_INSTALL=	vimb-gtk2-*

USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_TAGNAME=	cd61814
PLIST_FILES=	bin/vimb man/man1/vimb.1.gz

MAKE_ENV=	GTK="3"
USES=		gmake pkgconfig
USE_GNOME=	gtk30

post-extract:
	${MV}	${WRKSRC}/src/config.def.h ${WRKSRC}/src/config.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vimb.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/vimb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
