# $FreeBSD$

PORTNAME=	hq
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
PKGNAMEPREFIX=	elasticsearch-plugin-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch HQ Plugin

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=1.7.0:textproc/elasticsearch

CONFLICTS=	elasticsearch2-plugin-hq-2.*

USE_GITHUB=	yes
GH_ACCOUNT=	royrusso
GH_PROJECT=	elasticsearch-HQ
NO_ARCH=	yes

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ
	cd ${WRKSRC} && ${COPYTREE_SHARE} _site ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ
	${INSTALL_DATA} ${WRKSRC}/*.properties ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/HQ

.include <bsd.port.mk>
