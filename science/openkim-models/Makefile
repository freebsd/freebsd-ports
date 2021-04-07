PORTNAME=	openkim-models
DISTVERSION=	2021-01-28
CATEGORIES=	science
MASTER_SITES=	https://s3.openkim.org/archives/collection/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Knowledgebase of Interatomic Models

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim-console
LIB_DEPENDS=	libkim-api.so:science/kim-api

USES=		cmake:noninja compiler:c++11-lang fortran tar:txz

.include <bsd.port.mk>
