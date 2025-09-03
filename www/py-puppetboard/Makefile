PORTNAME=	puppetboard
PORTVERSION=	6.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB
WWW=		https://github.com/voxpupuli/puppetboard

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2025.4.26:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}charset-normalizer>=3.4.2:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}CommonMark>=0.9.1:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-apscheduler>=1.13.1:www/py-flask-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-caching>=2.2.0:www/py-flask-caching@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask_wtf>=1.2.1:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.1.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.10:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=2.2.0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=3.0.2:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=25.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.2.3:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb>=3.2.0:databases/py-pypuppetdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.2:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.20:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.1.3:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtforms>=3.1.2:textproc/py-wtforms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipp>=3.21.0:devel/py-zipp@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

SUB_LIST=	ETCDIR=${ETCDIR}
SUB_FILES=	wsgi.py.sample

NO_ARCH=	yes

GH_ACCOUNT=	voxpupuli
PLIST_FILES=	"@sample etc/puppetboard/settings.py.sample" \
		"@sample %%WWWDIR%%/wsgi.py.sample"

post-patch:
	${REINPLACE_CMD} -e '/requirements_for_tests/,+2d' \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} -e "s,importlib.metadata.version('puppetboard'),'${PORTVERSION}'," \
		${WRKSRC}/puppetboard/version.py

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/settings.py.sample ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/wsgi.py.sample ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
