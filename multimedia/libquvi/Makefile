# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	libquvi-scripts>=0.4.0:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:0.4.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		iconv lua pathfix pkgconfig tar:xz

PROJECTHOST=	quvi

post-patch:
	@${REINPLACE_CMD} 's/lua-5.1/lua-${LUA_VER}/g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
