# $FreeBSD$

PORTNAME=	antioch
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0-156
DISTVERSIONSUFFIX=	-g90ffa43
PORTREVISION=	8
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ Chemical Kinetics, Thermodynaimics, and Transport Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/metaphysicl/metaphysicl_version.h:science/metaphysicl \
		${LOCALBASE}/include/viennacl/vector.hpp:math/viennacl
LIB_DEPENDS=	libgsl.so:math/gsl \
		libOpenCL.so:devel/ocl-icd

USES=		autoreconf compiler:c++11-lang eigen:3 gmake libtool localbase
USE_GITHUB=	yes
GH_ACCOUNT=	libantioch
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-static \
		--enable-eigen --with-eigen-include=${LOCALBASE}/include/eigen3 \
		--enable-opencl \
		--with-metaphysicl=${LOCALBASE} \
		--with-viennacl=${LOCALBASE}/include \
		--with-gsl=${LOCALBASE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libantioch.so.0.0.0

.include <bsd.port.mk>
