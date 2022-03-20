PORTNAME=	kim-api
DISTVERSION=	2.3.0
CATEGORIES=	science
MASTER_SITES=	https://s3.openkim.org/kim-api/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for reliable, reproducible, portable molecular simulations

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	xxd:editors/vim

USES=		cmake:noninja fortran tar:txz
USE_LDCONFIG=	yes

post-install:
	${REINPLACE_CMD} -i '' -e 's|#!/bin/bash|#!/bin/sh|' ${STAGEDIR}${PREFIX}/bin/kim-api-collections-management
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc

.include <bsd.port.mk>
