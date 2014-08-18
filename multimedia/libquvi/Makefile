# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libquvi/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	libquvi
PORTVERSION=	0.9.4
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	AGPLv3

BUILD_DEPENDS=	libquvi-scripts>=0.9:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libproxy.so:${PORTSDIR}/net/libproxy \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:0.4.[0-9]*

USES=		iconv lua pathfix pkgconfig tar:xz
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

QUVI_VER=	0.9
PLIST_SUB+=	VERSION=${QUVI_VER}

PROJECTHOST=	quvi

post-patch:
	@${REINPLACE_CMD} 's/lua-5.1/lua-${LUA_VER}/g' ${WRKSRC}/configure

.include <bsd.port.mk>
