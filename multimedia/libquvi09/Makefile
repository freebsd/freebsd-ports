# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE
PKGNAMESUFFIX=	09

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	AGPLv3

BUILD_DEPENDS=	libquvi-scripts09>=0.9:${PORTSDIR}/multimedia/libquvi-scripts09
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libproxy.so:${PORTSDIR}/net/libproxy \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

USES=		iconv libtool lua pathfix pkgconfig tar:xz
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--program-suffix=09
INSTALL_TARGET=	install-strip

QUVI_VER=	0.9
PLIST_SUB+=	VERSION=${QUVI_VER}

PROJECTHOST=	quvi

post-patch:
	@${REINPLACE_CMD} 's/lua-5.1/lua-${LUA_VER}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
