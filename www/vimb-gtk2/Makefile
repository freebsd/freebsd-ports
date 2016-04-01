# $FreeBSD$

PORTNAME?=	vimb-gtk2
PORTVERSION=	2.11
CATEGORIES=	www

MAINTAINER=	mike.d.ft402@gmail.com
COMMENT=	Vim like browser

LICENSE=	GPLv3

LIB_DEPENDS?=	libwebkitgtk-1.0.so:www/webkit-gtk2

USE_GITHUB=	yes
GH_ACCOUNT=	fanglingsu
GH_PROJECT=	vimb
PLIST_FILES=	bin/vimb man/man1/vimb.1.gz

MAKE_ENV?=	GTK="2"
USE_GNOME?=	gtk20
USES=		gmake pkgconfig

CONFLICTS?=	vimb-gtk3-*

.include <bsd.port.pre.mk>

post-extract:
	${MV} ${WRKSRC}/src/config.def.h ${WRKSRC}/src/config.h
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
# cc on FreeBSD-9 does not know -Wno-typedef-redefinition
	${REINPLACE_CMD} -e 's|-Wno-typedef-redefinition|-Wall|' \
		${WRKSRC}/config.mk
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/doc/vimb.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/src/vimb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
