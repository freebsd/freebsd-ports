# $FreeBSD$

PORTNAME=	rabbitmq
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://download.elasticsearch.org/elasticsearch/elasticsearch-river-rabbitmq/
PKGNAMEPREFIX=	elasticsearch-river-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	ElasticSearch RabbitMQ River

LICENSE=	APACHE20

RUN_DEPENDS=	elasticsearch>=1.6.0:textproc/elasticsearch

USES=		zip

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/river-rabbitmq
	${INSTALL_DATA} ${WRKDIR}/*.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins/river-rabbitmq

.include <bsd.port.mk>
