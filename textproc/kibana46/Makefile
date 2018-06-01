# Created by: Sergey Kozlov <kozlov.sergey.404@gmail.com>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	4.6.4
DISTVERSIONSUFFIX=	-linux-x86
CATEGORIES=	textproc www
MASTER_SITES=	https://download.elastic.co/kibana/kibana/ \
		http://download.elastic.co/kibana/kibana/
PKGNAMESUFFIX=	46

DEPRECATED=	End of Life was 2018-02-28
EXPIRATION_DATE=	2018-07-09

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

RUN_DEPENDS=	node6>=6.9.0:www/node6

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
