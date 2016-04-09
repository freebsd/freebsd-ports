# $FreeBSD$

PORTNAME=	migration
PORTVERSION=	0.17
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch Migration Plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=0.90.9:textproc/elasticsearch

USE_GITHUB=	yes
GH_ACCOUNT=	elastic
GH_PROJECT=	elasticsearch-migration

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/migration/_site
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/migration/_site

.include <bsd.port.mk>
