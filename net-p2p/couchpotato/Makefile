# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	couchpotato
PORTVERSION=	0.0.20161225
PORTREVISION=	2
CATEGORIES=	net-p2p python

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Automatic NZB and torrent downloader

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		fpc-libcurl>0:ftp/fpc-libcurl \
		docbook-xml>0:textproc/docbook-xml

USE_RC_SUBR=	couchpotato
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

NO_ARCH=	yes
NO_BUILD=	yes

USES=		python shebangfix
SHEBANG_FILES=	CouchPotato.py

USERS=		couchpotato

USE_GITHUB=	yes
GH_ACCOUNT=	CouchPotato
GH_PROJECT=	CouchPotatoServer
GH_TAGNAME=	b538f9a

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
