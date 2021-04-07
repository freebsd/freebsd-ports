PORTNAME=	kim-api
DISTVERSION=	2.2.1
CATEGORIES=	science
MASTER_SITES=	https://s3.openkim.org/kim-api/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for reliable, reproducible, portable molecular simulations

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE.CDDL

BUILD_DEPENDS=	xxd:editors/vim-console

USES=		cmake:noninja fortran tar:txz
USE_LDCONFIG=	yes

post-install:
	${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/kim-api-collections-management
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
