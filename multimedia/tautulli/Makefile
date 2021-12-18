# Created by: Mark Felder <feld@FreeBSD.org>

PORTNAME=	tautulli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	multimedia python

MAINTAINER=	christer.edwards@gmail.com
COMMENT=	Monitoring, analytics, and notifications for Plex Media Server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cpe python:3.5+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Tautulli
GH_PROJECT=	Tautulli
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	Tautulli.py
python_OLD_CMD=	/bin/sh

NO_ARCH=	yes
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USERS=		tautulli
GROUPS=		tautulli

PORTDOCS=	API.md CHANGELOG.md README.md

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

post-install:
	@${FIND} -s ${STAGEDIR}${WWWDIR} -type d -empty -delete
	@${FIND} -s ${STAGEDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
