PORTNAME=	server
PORTVERSION=	${GLPI_VER}.${FUNV_VER}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
PKGNAMEPREFIX=	glpi-plugins-fusioninventory-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Plugin of glpi to get information of networking devices
WWW=		https://fusioninventory.org/

LICENSE=	AGPLv3

DEPRECATED=	Requires php80 which is set to expire on 2023-11-26
EXPIRATION_DATE=	2023-12-31

RUN_DEPENDS=	glpi>=9.5:www/glpi

USES=		gettext php shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	fusioninventory
GH_PROJECT=	fusioninventory-for-glpi
GH_TAGNAME=	glpi090+${FUNV_VER}
USE_PHP=	fileinfo simplexml
IGNORE_WITH_PHP=	81 82 83

GLPI_VER=	9.5.0
FUNV_VER=	1.5
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	lib/mustache.js-2.0.0/hooks/install-hooks.sh \
		scripts/get_agent_jobs.php scripts/cleanup_repository.php \
		scripts/prepare_jobs.php scripts/get_job_logs.php \
		tools/extract_template.sh
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

GLPIPLUGINDIR?=	www/glpi/plugins

.include <bsd.port.pre.mk>
do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@${CP} -R ${WRKSRC} ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}/fusioninventory

.include <bsd.port.post.mk>
