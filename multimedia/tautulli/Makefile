# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	tautulli
PORTVERSION=	2.7.3
DISTVERSIONPREFIX=v
CATEGORIES=	multimedia python

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Monitoring, analytics, and notifications for Plex Media Server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		python:3.5+ shebangfix
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	Tautulli.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
python_OLD_CMD=	/bin/sh
GH_ACCOUNT=	Tautulli
GH_PROJECT=	Tautulli

NO_ARCH=	yes
PORTDOCS=	API.md CHANGELOG.md README.md

USERS=		tautulli
GROUPS=		tautulli

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "data lib plexpy" ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Tautulli.py ${STAGEDIR}${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${WWWDIR}/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install:
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type d -empty -delete
	@${FIND} -s ${STAGEDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
