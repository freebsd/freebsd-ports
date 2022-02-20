# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>

PORTNAME=	smarty
PORTVERSION=	2.6.32
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/files/docs/:manual
DISTFILES=	manual-en-${PORTVERSION:R}.zip:manual
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP compiling template engine

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.lib

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
NO_BUILD=	yes
USES=		cpe php:web,flavors
USE_PHP=	pcre

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

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
