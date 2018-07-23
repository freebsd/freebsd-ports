# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	privatebin
PORTVERSION=	1.2
CATEGORIES=	www security

MAINTAINER=	se@FreeBSD.org
COMMENT=	Simple end-to-end encrypting zero-knowledge paste-bin server

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NO_BUILD=	yes
NO_ARCH=	yes

USES=		php
USE_PHP=	gd hash json wddx zlib
USE_GITHUB=	yes
GH_PROJECT=	PrivateBin

post-patch:
	@${REINPLACE_CMD} -e 's:%%DATADBDIR%%:/var/db/${PORTNAME}:' \
		${WRKSRC}/index.php

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MV} ${STAGEDIR}/${WWWDIR}/*.md ${STAGEDIR}/${DOCSDIR}
	@${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
