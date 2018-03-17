# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tautulli
PORTVERSION=	2.0.22
PORTREVISION=	0
CATEGORIES=	multimedia python
DISTVERSIONPREFIX=v

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Monitoring, analytics, and notifications for Plex Media Server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USES=		python:2.7 shebangfix
SHEBANG_FILES=	Tautulli.py
python_OLD_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	Tautulli
GH_PROJECT=	Tautulli
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/data ${STAGEDIR}${WWWDIR}/lib \
		${STAGEDIR}${WWWDIR}/plexpy
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} plexpy ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Tautulli.py ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${WWWDIR}

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
