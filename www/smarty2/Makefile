PORTNAME=	smarty
PORTVERSION=	2.6.32
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/files/docs/:manual
PKGNAMESUFFIX=	2${PHP_PKGNAMESUFFIX}
DISTFILES=	manual-en-${PORTVERSION:R}.zip:manual

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP compiling template engine
WWW=		https://www.smarty.net/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.lib

DEPRECATED=	Does not support current php versions in tree
EXPIRATION_DATE=	2024-05-04

USES=		cpe php:web,flavors
USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	cd ${WRKDIR}/manual-en && ${FIND} . | ${CPIO} --quiet -dump ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>
