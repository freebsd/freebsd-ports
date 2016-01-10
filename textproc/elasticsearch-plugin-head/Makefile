# $FreeBSD$

PORTNAME=	head
PORTVERSION=	2015.12.16
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch Head Plugin

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	mobz
GH_PROJECT=	elasticsearch-head
GH_TAGNAME=	8fe463f

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/head
	cd ${WRKSRC} && ${COPYTREE_SHARE} _site ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/head
	${INSTALL_DATA} ${WRKSRC}/*.properties ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/head

.include <bsd.port.mk>
