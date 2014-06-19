# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	templatelite
PORTVERSION=	2.10
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Template%20Lite/Template%20Lite%20version%20${PORTVERSION}
DISTNAME=	template_lite_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Smaller, faster alternative to the Smarty template engine

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes
WRKSRC=		${WRKDIR}/template_lite
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
