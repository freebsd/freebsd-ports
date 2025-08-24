PORTNAME=	calibreweb
PORTVERSION=	0.6.25
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@wener.org
COMMENT=	Web interface for viewing and downloading eBooks from a Calibre DB
WWW=		https://github.com/janeczku/calibre-web

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}APScheduler>=0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-babel>=0:devel/py-flask-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-HTTPAuth>=0:security/py-flask-httpauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Principal>=0:www/py-flask-principal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask_limiter>=0:www/py-flask-limiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask_wtf>=0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso-639>=0:textproc/py-iso-639@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces-plus>=0:net/py-netifaces-plus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycountry>=0:textproc/py-pycountry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>=0:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Wand>=0:graphics/py-wand@${PY_FLAVOR}

USES=		python ssl
USE_PYTHON=	autoplist cryptography pep517
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	GROUP=${GROUPS} \
		PORTNAME=${PORTNAME} \
		PYTHON_CMD=${PYTHON_CMD} \
		RC_NAME=calibreweb \
		USER=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

POST_PLIST=	fix-plist
PORTDOCS=	PKG-INFO README.md

# GDRIVE option removed due to expired security/py-oauth2client
OPTIONS_DEFINE=		CALIBRE COMICS DOCS GMAIL GREADS KOBO LDAP METADATA \
			OAUTH
OPTIONS_DEFAULT=	IMAGICK7_X11 SQLA20

OPTIONS_SINGLE=		IMAGICK SQLA
OPTIONS_SINGLE_IMAGICK=	IMAGICK6_NOX11 IMAGICK6_X11 IMAGICK7_NOX11 IMAGICK7_X11
OPTIONS_SINGLE_SQLA=	SQLA14 SQLA20

CALIBRE_DESC=		Calibre Desktop Conversion and Metadata Editing
COMICS_DESC=		Comic Metadata Support
GMAIL_DESC=		GMail
GREADS_DESC=		Goodreads API
IMAGICK6_NOX11_DESC=	ImageMagick6 without X11 support
IMAGICK6_X11_DESC=	ImageMagick6 with X11 support
IMAGICK7_NOX11_DESC=	ImageMagick7 without X11 support
IMAGICK7_X11_DESC=	ImageMagick7 with X11 support
IMAGICK_DESC=		${IMAGEMAGICK_DESC}
KOBO_DESC=		Kobo Device Support
LDAP_DESC=		LDAP Login Support
METADATA_DESC=		Metadata Extraction Support
OAUTH_DESC=		OAuth Login
SQLA14_DESC=		Use SQLAlchemy 1.4.*
SQLA20_DESC=		Use SQLAlchemy 2.0.*
SQLA_DESC=		SQLAchemy Database Toolkit for Python

CALIBRE_RUN_DEPENDS=	calibre>=0:deskutils/calibre
COMICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comicapi>=0:archivers/py-comicapi@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}natsort>=0:devel/py-natsort@${PY_FLAVOR}
GMAIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}google-auth-oauthlib>=0:security/py-google-auth-oauthlib@${PY_FLAVOR}
GREADS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}goodreads>=0:devel/py-goodreads@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}Levenshtein>=0:devel/py-Levenshtein@${PY_FLAVOR}
IMAGICK6_NOX11_USES=	magick:6,run,nox11
IMAGICK6_X11_USES=	magick:6,run
IMAGICK7_NOX11_USES=	magick:7,run,nox11
IMAGICK7_X11_USES=	magick:7,run
KOBO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
			kepubify>=0:textproc/kepubify
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask-SimpleLDAP>=0:www/py-flask-simpleldap@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-ldap>=0:net/py-python-ldap@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy-utils>=0:databases/py-sqlalchemy-utils@${PY_FLAVOR}
METADATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}faust-cchardet>=0:textproc/py-faust-cchardet@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}html2text>=0:textproc/py-html2text@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown2>=0:textproc/py-markdown2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}py7zr>=0:archivers/py-py7zr@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycountry>=0:textproc/py-pycountry@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rarfile>=0:archivers/py-rarfile@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scholarly>=0:devel/py-scholarly@${PY_FLAVOR} \
			unrar>=0:archivers/unrar
OAUTH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-dance>=0:www/py-flask-dance@${PY_FLAVOR}
SQLA14_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR}
SQLA20_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=0:databases/py-sqlalchemy20@${PY_FLAVOR}

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install:
# Remove .HOMEDIR so we can specify the location for the config files
	(cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/calibreweb/cps && ${RM} .HOMEDIR)

fix-plist:
	@${REINPLACE_CMD} -e "s|.*HOMEDIR$$||" ${TMPPLIST}

.include <bsd.port.mk>
