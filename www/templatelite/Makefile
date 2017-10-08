# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	templatelite
PORTVERSION=	2.10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Template%20Lite/Template%20Lite%20version%20${PORTVERSION}
DISTNAME=	template_lite_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smaller, faster alternative to the Smarty template engine

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
NO_ARCH=	yes
USES=		php:web
USE_PHP=	pcre
WRKSRC=		${WRKDIR}/template_lite
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
