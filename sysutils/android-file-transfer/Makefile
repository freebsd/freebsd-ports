PORTNAME=	android-file-transfer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5
PORTREVISION=	4
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Android MTP client with minimalistic UI
WWW=		https://github.com/whoozle/android-file-transfer-linux

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=        cli fuse qt6
FLAVOR?=        ${FLAVORS:[1]}

USES=		cmake compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	whoozle
GH_PROJECT=	${PORTNAME}-linux

.if ${FLAVOR} == cli
CMAKE_OFF=	BUILD_FUSE \
		BUILD_QT_UI
.elif ${FLAVOR} == fuse
USES+=		fuse:3
CMAKE_ON=	BUILD_FUSE
CMAKE_OFF=	BUILD_QT_UI
.elif ${FLAVOR} == qt6
USES+=		qt:6
USE_QT=		base tools:build
CMAKE_OFF=	BUILD_FUSE
CMAKE_ON=	BUILD_QT_UI
.endif

CMAKE_ON+=	USB_BACKEND_LIBUSB BUILD_MTPZ
CMAKE_OFF+=	BUILD_PYTHON

FLAVORS_SUB=	yes

PORTSCOUT=	skipv:continuous

OPTIONS_DEFINE=		OPENSSL TAGLIB
OPTIONS_DEFAULT=	OPENSSL TAGLIB

TAGLIB_DESC=		Reading audio metadata via taglib
OPENSSL_DESC=		MTPZ support via OpenSSL

OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	BUILD_MTPZ

TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_BOOL=	BUILD_TAGLIB

post-patch:
	@${REINPLACE_CMD} '/set.*AFT_VERSION/s/".*"/"${DISTVERSIONFULL}"/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
