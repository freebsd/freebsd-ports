# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
PORTVERSION=	3.1.3
CATEGORIES=	textproc www
MASTER_SITES=	http://download.elasticsearch.org/kibana/kibana/
PKGNAMESUFFIX=	3

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

DEPRECATED=	End of Life was 2015-11-15
EXPIRATION_DATE=	2018-06-01

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${MV} ${STAGEDIR}${WWWDIR}/config.js ${STAGEDIR}${WWWDIR}/config.js.sample

.include <bsd.port.mk>
