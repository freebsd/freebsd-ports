# $FreeBSD$

PORTNAME=	assimp
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to import various 3D model formats in a uniform manner

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libminizip.so:archivers/minizip

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_OFF=	ASSIMP_BUILD_TESTS

PLIST_SUB=	SHL3=${DISTVERSION} VER2=${DISTVERSION:R} SHL1=${DISTVERSION:R:R}

post-install: # rm the third-party lib installed by mistake: https://github.com/assimp/assimp/issues/1650
	@${RM} ${STAGEDIR}${PREFIX}/lib/libIrrXML.a

.include <bsd.port.mk>
