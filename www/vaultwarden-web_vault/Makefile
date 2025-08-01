PORTNAME=	vaultwarden
PORTVERSION=	2025.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www security
MASTER_SITES=	https://github.com/dani-garcia/bw_web_builds/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMESUFFIX=	_web-vault
DISTNAME=	bw_web_${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Vaultwarden WebUI
WWW=		https://github.com/dani-garcia/bw_web_builds

LICENSE=	GPLv3

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
