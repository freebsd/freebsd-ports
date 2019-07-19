# $FreeBSD$

PORTNAME=	kim-api
DISTVERSION=	2.1.0
CATEGORIES=	science
MASTER_SITES=	https://s3.openkim.org/kim-api/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for reliable, reproducible, portable molecular simulations

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE.CDDL

BUILD_DEPENDS=	xxd:editors/vim-console

USES=		cmake:noninja fortran tar:txz
USE_LDCONFIG=	yes

.include <bsd.port.mk>
