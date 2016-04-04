# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	server
PORTVERSION=	${GLPI_VER}.${FUNV_VER}
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://forge.fusioninventory.org/attachments/download/1875/
PKGNAMEPREFIX=	glpi-plugins-fusioninventory-
DISTNAME=	fusioninventory-for-glpi_${GLPI_VER}+${FUNV_VER}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Plugin of glpi to get information of networking devices

LICENSE=	AGPLv3

RUN_DEPENDS=	glpi>=0.85:www/glpi

USE_PHP=	fileinfo simplexml wddx
USES=		gettext
GLPI_VER=	0.85
FUNV_VER=	1.2
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

GLPIPLUGINDIR?=	www/glpi/plugins

do-install:
.for i in get_agent_jobs.php cleanup_repository.php prepare_jobs.php get_job_logs.php
	@${REINPLACE_CMD} 's!/usr/bin/php!/usr/bin/env php!;' \
		${WRKSRC}/fusioninventory/scripts/${i}
	@${CHMOD} -x ${WRKSRC}/fusioninventory/scripts/${i}
	@${RM} ${WRKSRC}/fusioninventory/scripts/${i}.bak
.endfor
	@${CHMOD} -x ${WRKSRC}/fusioninventory/lib/mustache.js-2.0.0/hooks/install-hooks.sh
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@${CP} -R ${WRKSRC}/fusioninventory ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}

.include <bsd.port.mk>
