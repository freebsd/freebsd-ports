# Created by: delphij@FreeBSD.org

PORTNAME=	libvmime
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All-in-one Internet mail library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgsasl.so:security/libgsasl

USES=		cmake:noninja compiler:c++11-lib pkgconfig

CMAKE_ARGS=	-DLIB_SUFFIX=""
CMAKE_OFF=	VMIME_BUILD_SAMPLES VMIME_SHARED_PTR_USE_BOOST
CMAKE_ON=	VMIME_SHARED_PTR_USE_CXX
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kisli
GH_PROJECT=	vmime

OPTIONS_DEFINE=	ICU
ICU_DESC=	Use icu instead of iconv for charset conversion

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_USES_OFF=		iconv

.include <bsd.port.mk>
