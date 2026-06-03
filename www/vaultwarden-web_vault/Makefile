PORTNAME=	vaultwarden
PORTVERSION=	${BW_WEB_VERSION}${BW_WEB_BUILD:S/+build//}
CATEGORIES=	www security
MASTER_SITES=	https://github.com/dani-garcia/bw_web_builds/releases/download/v${BW_WEB_VERSION}${BW_WEB_BUILD}/
PKGNAMESUFFIX=	_web-vault
DISTFILES=	bw_web_v${BW_WEB_VERSION}${BW_WEB_BUILD}.tar.gz

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Vaultwarden WebUI
WWW=		https://github.com/dani-garcia/bw_web_builds

LICENSE=	GPLv3

# Ugly hack to prevent confusion "build" as "beta"
# 2025.12.1 > 2025.12.1+b3/2025.12.1+build.3
# Comment out BW_WEB_BUILD when no build suffix is needed
BW_WEB_VERSION=	2026.4.1
#BW_WEB_BUILD=   +build.3

WRKSRC=		${WRKDIR}/web-vault

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/web-vault
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/web-vault)
	(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL}/web-vault,' >> ${TMPPLIST}

.include <bsd.port.mk>
