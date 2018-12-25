# Created by: delphij@FreeBSD.org
# $FreeBSD$

PORTNAME=	libvmime
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	All-in-one Internet mail library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgsasl.so:security/gsasl

USE_GITHUB=	yes
GH_ACCOUNT=	kisli
GH_PROJECT=	vmime

USES=		cmake:noninja compiler:c++11-lib iconv pkgconfig
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_SUFFIX:STRING="" \
		-DVMIME_BUILD_SAMPLES:BOOL=NO \
		-DVMIME_SHARED_PTR_USE_BOOST:BOOL=NO \
		-DVMIME_SHARED_PTR_USE_CXX:BOOL=YES

post-patch:
	@${REINPLACE_CMD} 's,$${VMIME_INSTALL_LIBDIR}/pkgconfig,${PREFIX}/libdata/pkgconfig,' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
