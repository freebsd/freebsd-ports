# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	smarty
PORTVERSION=	2.6.29
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/files/docs/:manual
DISTFILES=	manual-en-${PORTVERSION:R}.zip:manual

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	PHP compiling template engine

LICENSE=	LGPL21

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	smarty-php

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in BUGS FAQ INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/manual
	cd ${WRKDIR}/manual-en && ${FIND} . | ${CPIO} --quiet -dump ${STAGEDIR}${DOCSDIR}/manual

.include <bsd.port.mk>
