PORTNAME=	offlineimap3
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0-70
DISTVERSIONSUFFIX=	-g${GH_TAGNAME}
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Two-way synchronization of local Maildir and IMAP folders
WWW=		https://github.com/OfflineIMAP/offlineimap3

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# setup.py requires these during build time. Possible move to setup/install_requires:
# https://github.com/OfflineIMAP/offlineimap3/issues/110
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imaplib2>=3.5:mail/py-imaplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc6555>=0:mail/py-rfc6555@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2020.6.20:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imaplib2>=3.5:mail/py-imaplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc6555>=0:mail/py-rfc6555@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.9:net/py-urllib3@${PY_FLAVOR}

USES=		python

# Project is currently not publishing to pypi sdist.  pypi/naming status:
# https://github.com/OfflineIMAP/offlineimap3/issues/111
USE_GITHUB=	yes
GH_ACCOUNT=	OfflineIMAP
GH_TAGNAME=	93f358dee9d7cf800d11679ee4e9c61abfc0c5f6

USE_PYTHON=	autoplist concurrent distutils pytest

CONFLICTS_INSTALL=	mail/py-offlineimap

NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	offlineimap.conf

OPTIONS_DEFINE=		DOCS EXAMPLES GSSAPI KEYRING MANPAGES
OPTIONS_DEFAULT=	KEYRING MANPAGES

KEYRING_DESC=		GNOME keyring support

COMMON_BUILD_DEPENDS=	a2x:textproc/asciidoc \
			gmake:devel/gmake

DOCS_BUILD_DEPENDS=	${COMMON_BUILD_DEPENDS} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR}

GSSAPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.6.9:security/py-gssapi@${PY_FLAVOR}

KEYRING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${PY_FLAVOR}

MANPAGES_BUILD_DEPENDS=	${COMMON_BUILD_DEPENDS}
MANPAGES_PLIST_FILES+=	share/man/man1/offlineimap.1.gz \
			share/man/man7/offlineimapui.7.gz

# In concurrent env. sphinx-build is only exist for py38 add "-${PYTHON_VER}" to command
post-patch:
	cd ${WRKSRC} && \
	${REINPLACE_CMD} '/^SPHINXBUILD = sphinx-build$$/s/$$/-${PYTHON_VER}/' \
		docs/Makefile

post-build-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${GMAKE} docs && \
	cd html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		'! ( -name .lock -or -name .buildinfo )'

post-build-MANPAGES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man7/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man1/
	cd ${WRKSRC}/docs && ${GMAKE} man && \
	${INSTALL_MAN} offlineimapui.7 ${STAGEDIR}${PREFIX}/share/man/man7/ && \
	${INSTALL_MAN} offlineimap.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/offlineimap.conf ${STAGEDIR}${EXAMPLESDIR}

pre-test:
	cd ${WRKSRC} && \
	${CP} test/credentials.conf.sample test/credentials.conf

.include <bsd.port.mk>
