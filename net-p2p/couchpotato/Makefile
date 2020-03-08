# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	couchpotato
PORTVERSION=	0.0.20170327
PORTREVISION=	2
CATEGORIES=	net-p2p python

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Automatic NZB and torrent downloader

LICENSE=	GPLv3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR}

USE_RC_SUBR=	couchpotato
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} USERS=${USERS}

NO_ARCH=	yes
NO_BUILD=	yes

USES=		python:2.7 shebangfix
SHEBANG_FILES=	CouchPotato.py

USERS=		couchpotato
GROUPS=		couchpotato

USE_GITHUB=	yes
GH_ACCOUNT=	CouchPotato
GH_PROJECT=	CouchPotatoServer
GH_TAGNAME=	711310d

OPTIONS_DEFINE=	UNRAR
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
