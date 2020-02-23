# Created by: delphij@FreeBSD.org
# $FreeBSD$

PORTNAME=	libvmime
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=	mail

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All-in-one Internet mail library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgsasl.so:security/libgsasl

USES=		cmake:noninja compiler:c++11-lib iconv pkgconfig

CMAKE_ARGS=	-DLIB_SUFFIX=""
CMAKE_OFF=	VMIME_BUILD_SAMPLES VMIME_SHARED_PTR_USE_BOOST
CMAKE_ON=	VMIME_SHARED_PTR_USE_CXX
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kisli
GH_PROJECT=	vmime

post-patch:
	@${REINPLACE_CMD} 's|$${VMIME_INSTALL_LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
