# Created by: Sergey Kozlov <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION?=	4.2.2
DISTVERSIONSUFFIX=	-linux-x86
PORTREVISION?=	1
CATEGORIES=	textproc www
MASTER_SITES=	https://download.elastic.co/kibana/kibana/ \
		http://download.elastic.co/kibana/kibana/
PKGNAMESUFFIX?=	42

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node012>=0:www/node012

DEPRECATED=	not actively supported - use kibana 4.5 (textproc/kibana45) instead
EXPIRATION_DATE=2016-06-27

NO_BUILD=	yes
NO_ARCH=	yes
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
USE_RC_SUBR=	${PORTNAME}

do-install:
	${CP} ${WRKSRC}/config/kibana.yml ${STAGEDIR}${PREFIX}/etc/kibana.yml.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && \
		${RM} -r bin config node && \
		${RM} -r optimize/* && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
