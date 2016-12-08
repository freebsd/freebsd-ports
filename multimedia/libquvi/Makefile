# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi
PORTVERSION=	0.4.1
PORTREVISION=	5
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libquvi-scripts>=0.4.0:multimedia/libquvi-scripts
LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of Lua

PORTSCOUT=	limit:0.4.[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

PORTDOCS=	*

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=	lua

post-patch-LUAJIT-off:
	@${REINPLACE_CMD} 's|lua-5.1|lua-${LUA_VER}|g' ${WRKSRC}/configure

post-patch-LUAJIT-on:
	@${REINPLACE_CMD} 's|lua >= 5.1|luajit|g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
