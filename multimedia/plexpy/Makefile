# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plexpy
PORTVERSION=	1.4.16
PORTREVISION=	0
CATEGORIES=	multimedia python
DISTVERSIONPREFIX=v

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Monitoring, analytics, and notifications for Plex Media Server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USES=		python:2 shebangfix
SHEBANG_FILES=	PlexPy.py
python_OLD_CMD=	/bin/sh

USE_GITHUB=	yes
GH_ACCOUNT=	drzoidberg33
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/plexpy
	${MKDIR} ${STAGEDIR}${PREFIX}/plexpy/data
	${MKDIR} ${STAGEDIR}${PREFIX}/plexpy/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/plexpy/plexpy
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${PREFIX}/plexpy
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/plexpy
	cd ${WRKSRC} && ${COPYTREE_SHARE} plexpy ${STAGEDIR}${PREFIX}/plexpy
	${INSTALL_SCRIPT} ${WRKSRC}/PlexPy.py ${STAGEDIR}${PREFIX}/plexpy
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${STAGEDIR}${PREFIX}/plexpy

.include <bsd.port.mk>
