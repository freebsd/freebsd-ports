PORTNAME=		mtxclient
DISTVERSIONPREFIX=	v
DISTVERSION=		0.10.1
PORTREVISION=	1
CATEGORIES=		net-im

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Client API library for the Matrix protocol
WWW=		https://nheko.im/nheko-reborn/mtxclient/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>=3:devel/nlohmann-json
LIB_DEPENDS=	\
		libabsl_strings.so:devel/abseil \
		libcoeurl.so:ftp/coeurl \
		libfmt.so:devel/libfmt \
		libolm.so:security/olm \
		libre2.so:devel/re2 \
		libspdlog.so:devel/spdlog

USES=		cmake compiler:c++17-lang pkgconfig ssl \
		tar:xz
CMAKE_OFF=	BUILD_LIB_TESTS

USE_GITHUB=	yes
GH_ACCOUNT=	Nheko-Reborn

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
