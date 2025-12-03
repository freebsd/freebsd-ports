PORTNAME=	FlexGet
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.10
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multipurpose automation tool for all of your media
WWW=		https://flexget.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rebulk>=2.0.0:devel/py-rebulk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpyc>=5.0:devel/py-RPyC@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}APScheduler>=3.2.0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.4:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}loguru>=0.4.1:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.7:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=4.2:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}guessit>=3.2.0:multimedia/py-guessit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynzb>0:news/py-pynzb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zxcvbn>0:security/py-zxcvbn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plumbum>=1.2:sysutils/py-plumbum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.8.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.2:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=9.0.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyrss2gen>0:textproc/py-pyrss2gen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cherrypy>=3.7.0:www/py-cherrypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=0.7:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Compress>=1.2.1:www/py-flask-compress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Cors>=2.1.2:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>=0.4.0:www/py-flask-login@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-restx>=0.5.1:www/py-flask-restx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>=0.11:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysftp>0:ftp/py-sftp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517 pytest
GH_PROJECT=	Flexget
NO_ARCH=	yes

.include <bsd.port.mk>
