# Created by: Jeremy Norris <ishmael272home.com>
# $FreeBSD$

PORTNAME=	qt-gui
PORTVERSION=	1.9.0
PORTREVISION=	5
CATEGORIES=	net-im
PKGNAMEPREFIX=	licq-
PKGNAMESUFFIX?=	${KDE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt plugin for licq

LICENSE=	GPLv2

BUILD_DEPENDS=	licq:${LICQ_PORT}
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	licq:${LICQ_PORT} \
		${LOCALBASE}/lib/licq/protocol_icq.so:${LICQ_PORT}-icq

USES=		cmake qt:5 xorg
USE_XORG=	x11 xext ice xscrnsaver sm
USE_QT=		buildtools_build qmake_build linguisttools_build core \
		xml gui network dbus svg widgets
USE_GITHUB=	yes
GH_ACCOUNT=	licq-im
GH_PROJECT=	licq
GH_TAGNAME=	f271d55
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/${PORTNAME}
CMAKE_ARGS+=	-DWITH_QT5:BOOL=ON

OPTIONS_DEFINE=	HUNSPELL
OPTIONS_DEFAULT=HUNSPELL

LICQ_PORT?=	net-im/licq

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CMAKE_ON=	-DHUNSPELL_INCLUDE_DIRS=${LOCALBASE}/include/hunspell \
			-DHUNSPELL_LIBRARIES=${LOCALBASE}/lib/libhunspell-1.7.so \
			-DHUNSPELL_FOUND:BOOL=ON
HUNSPELL_CMAKE_OFF=	-DHUNSPELL_FOUND:BOOL=OFF

.include <bsd.port.mk>
