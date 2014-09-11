# $FreeBSD$

PORTNAME=	vimb
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	The vim like browser

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_COMMIT=	74fb0a8
PLIST_FILES=	bin/vimb man/man1/vimb.1.gz

USES=		gmake pkgconfig

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

GTK2_LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
GTK2_USE=		GNOME=gtk20
GTK3_LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
GTK3_USE=		GNOME=gtk30
GTK3_MAKE_ENV=		GTK="3"

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vimb.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/vimb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
