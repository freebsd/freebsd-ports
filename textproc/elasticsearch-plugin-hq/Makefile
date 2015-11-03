# $FreeBSD$

PORTNAME=	hq
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch HQ Plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=0.90.9:${PORTSDIR}/textproc/elasticsearch

USE_GITHUB=	yes
GH_ACCOUNT=	royrusso
GH_PROJECT=	elasticsearch-HQ

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ/_site
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ/_site

.include <bsd.port.mk>
