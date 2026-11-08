PORTNAME=	openkim-models
DISTVERSION=	2021-08-11
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://s3.openkim.org/archives/collection/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Knowledgebase of Interatomic Models
WWW=		https://openkim.org/

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim
LIB_DEPENDS=	libkim-api.so:science/kim-api

USES=		cmake:noninja compiler:c++11-lang fortran tar:txz

CMAKE_ARGS=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5 # CMake 4.5 compatibility

.include <bsd.port.mk>
