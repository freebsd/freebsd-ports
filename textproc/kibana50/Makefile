# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	5.0.2
DISTVERSIONSUFFIX=	-linux-x86
CATEGORIES=	textproc www
MASTER_SITES=	https://artifacts.elastic.co/downloads/kibana/ \
		http://artifacts.elastic.co/downloads/kibana/
PKGNAMESUFFIX?=	50

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node4>=4.3.2:www/node4

CONFLICTS=	kibana[3-4]*

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
