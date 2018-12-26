# $FreeBSD$

PORTNAME=	xlife++
DISTVERSION=	2.0.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	https://uma.ensta-paristech.fr/soft/XLiFE++/var/files/src/
DISTNAME=	xlifepp-sources-v${DISTVERSION}-2018-05-09

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	XLiFE++: eXtended Library of Finite Elements in C++

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=		fails to compile: BlasUtil.h:63:63: no type named 'ReturnType' in 'Eigen::ScalarBinaryOpTraits<__attribute__

USES=		cmake eigen:3 fortran tar:tbz
USE_LDCONFIG=	yes

CMAKE_OFF=	XLIFEPP_ENABLE_ARPACK # should be ON, but it fails to build. Reported to their bugs ML.

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3/Eigen -I${LOCALBASE}/include/ARPACK++

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-extract: # delete bundled packages
	@${RM} -r ${WRKSRC}/ext/Eigen ${WRKSRC}/ext/ARPACK ${WRKSRC}/ext/ARPACK++

post-configure:
	@${REINPLACE_CMD} -E 's/.*(ARPACK|Eigen)/#&/' ${CONFIGURE_WRKSRC}/cmake_install.cmake

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r CMakeLists.txt VERSION.txt etc/visuTermVec.m etc/templates etc/gmsh

.include <bsd.port.mk>
