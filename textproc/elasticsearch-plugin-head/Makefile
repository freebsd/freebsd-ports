# $FreeBSD$

PORTNAME=	head
PORTVERSION=	2015.03.17
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch Head Plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=0.90.9:${PORTSDIR}/textproc/elasticsearch

USE_GITHUB=	yes
GH_ACCOUNT=	mobz
GH_PROJECT=	elasticsearch-head
GH_TAGNAME=	f3a85b2

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/head/_site
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/head/_site

.include <bsd.port.mk>
