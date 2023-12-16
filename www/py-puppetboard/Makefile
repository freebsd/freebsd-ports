PORTNAME=	puppetboard
PORTVERSION=	4.2.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB
WWW=		https://github.com/voxpupuli/puppetboard

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}CommonMark>=0.9.1:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=2:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=2:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.9:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb>=0.3.3:databases/py-pypuppetdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=2:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtforms>=0:textproc/py-wtforms@${PY_FLAVOR}

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

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/settings.py.sample ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKDIR}/wsgi.py.sample ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
