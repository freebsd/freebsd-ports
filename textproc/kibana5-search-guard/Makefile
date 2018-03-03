# Created by: Miroslav Lachman <000.fbsd@quip.cz>
# $FreeBSD$

PORTNAME=	search-guard
PORTVERSION=	5.3.0
CATEGORIES=	textproc java
MASTER_SITES=	https://github.com/floragunncom/search-guard-kibana-plugin/releases/download/v5.3.0-2/
PKGNAMEPREFIX=	kibana5-
DISTNAME=	searchguard-kibana-5.3.0-2

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Kibana 5.3 Search Guard plugin

LICENSE=	APACHE20

RUN_DEPENDS=	kibana5>=5.3.0:textproc/kibana5

NO_BUILD=	yes

USES+=		zip

do-extract:
	@${MKDIR} ${WRKSRC}
	( cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} -d ${DISTNAME} \
	      ${_DISTDIR}${DISTFILES} )

do-install:
	@cd ${WRKSRC}/kibana && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/kibana5/plugins

.include <bsd.port.mk>
