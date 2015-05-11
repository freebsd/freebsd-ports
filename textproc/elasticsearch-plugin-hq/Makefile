# $FreeBSD$

PORTNAME=	hq
PORTVERSION=	2014.10.02
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch HQ Plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=0.90.9:${PORTSDIR}/textproc/elasticsearch

USE_GITHUB=	yes
GH_ACCOUNT=	royrusso
GH_PROJECT=	elasticsearch-HQ
GH_TAGNAME=	603ae9e

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ/_site
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ/_site

.include <bsd.port.mk>
