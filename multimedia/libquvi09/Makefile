# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	libquvi
PORTVERSION=	0.9.4
PORTREVISION=	4
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/libquvi/ \
		LOCAL/sunpoet
PKGNAMESUFFIX=	09

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libproxy.so:net/libproxy \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	libquvi-scripts09>=0.9:multimedia/libquvi-scripts09

USES=		gnome iconv libtool lua pathfix pkgconfig tar:xz
USE_GNOME=	glib20

CONFIGURE_ARGS=	--program-suffix=${PKGNAMESUFFIX}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	PKGNAMESUFFIX=${PKGNAMESUFFIX} PORTVERSION=${PORTVERSION} QUVIVERSION=${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's/lua-5.1/lua-${LUA_VER}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
