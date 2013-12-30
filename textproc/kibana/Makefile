# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kibana
DISTVERSION=	3.0.0milestone4
CATEGORIES=	textproc www
MASTER_SITES=	http://download.elasticsearch.org/kibana/kibana/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Browser based analytics and search interface to ElasticSearch

LICENSE=	APACHE20

NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/config.js ${STAGEDIR}${WWWDIR}/config.js.sample

.include <bsd.port.mk>
