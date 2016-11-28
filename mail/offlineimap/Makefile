# Created by: nbm
# $FreeBSD$

PORTNAME=	offlineimap
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.9
CATEGORIES=	mail python

MAINTAINER=	mp39590@gmail.com
COMMENT=	Powerful IMAP/Maildir synchronization and reader support

## GPLv2 or any later version (with an OpenSSL exception)
LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

## later versions have sqlite3 backend, which is recommended for local storages
## with large amount of emails
## (add additional variable to use in {BUILD|RUN}_DEPENDS per porter's hb 5.8.2)
OIMAP_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3
BUILD_DEPENDS=	${OIMAP_DEPENDS}
RUN_DEPENDS=	${OIMAP_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	OfflineIMAP

USES=		python:2.7
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	offlineimap.conf offlineimap.conf.minimal

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '! -name Makefile'

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf.minimal ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
