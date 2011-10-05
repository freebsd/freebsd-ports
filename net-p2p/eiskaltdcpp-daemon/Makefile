# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-daemon
PORTVERSION=	2.2.1
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	EiskaltDC++ Direct Connect client daemon

LICENSE=	GPLv3

LIB_DEPENDS+=	eiskaltdcpp:${PORTSDIR}/net-p2p/eiskaltdcpp-lib

PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	4.2+
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/${PORTNAME}

CXXFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS+=	-DBUILD_LIB:BOOL=OFF
CMAKE_ARGS+=	-DUSE_QT:BOOL=OFF
CMAKE_ARGS+=	-DUSE_GTK:BOOL=OFF
CMAKE_ARGS+=	-DNO_UI_DAEMON:BOOL=ON
CMAKE_ARGS+=	-DEISKALTDCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/eiskaltdcpp"
CMAKE_ARGS+=	-DCREATE_MO:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"

BUILD_WRKSRC=	${WRKSRC}/nasdc
INSTALL_WRKSRC=	${WRKSRC}/nasdc

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

.include <bsd.port.post.mk>
