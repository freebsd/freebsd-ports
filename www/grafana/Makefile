# Created by: Bartek Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grafana
PORTVERSION=	1.7.0
CATEGORIES=	www
MASTER_SITES=	http://grafanarel.s3.amazonaws.com/

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Dashboard and graph editor for Graphite, InfluxDB & OpenTSDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

NO_BUILD=	yes

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.include <bsd.port.mk>
