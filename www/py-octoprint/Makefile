# $FreeBSD$

PORTNAME=	octoprint
PORTVERSION=	1.3.0.a
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@kyle-evans.net
COMMENT=	Web interface for controlling a 3D printer

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.11.1:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11.1:www/py-werkzeug \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.4.2:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}sockjs-tornado>=1.0.2:www/py-sockjs-tornado \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>=0.3.2:www/py-flask-login \
		${PYTHON_PKGNAMEPREFIX}Flask-Principal>=0.4:www/py-flask-principal \
		${PYTHON_PKGNAMEPREFIX}Flask-Babel>=0.11.1:devel/py-flask-babel \
		${PYTHON_PKGNAMEPREFIX}Flask-Assets>=0.12:www/py-flask-assets \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.4:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}serial>=3.2:comms/py-serial \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.17:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}watchdog>=0.8.2:devel/py-watchdog \
		${PYTHON_PKGNAMEPREFIX}sarge>=0.1.4:devel/py-sarge \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}pylru>=1.0.9:devel/py-pylru \
		${PYTHON_PKGNAMEPREFIX}rsa>=3.3:security/py-rsa \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.2.1:sysutils/py-pkginfo \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}semantic_version>=2.4.2:devel/py-semantic_version \
		${PYTHON_PKGNAMEPREFIX}psutil>=4.3.0:sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}click>=6.6:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}awesome-slugify>=1.6.5:textproc/py-awesome-slugify \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.2.1:textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}chainmap>=1.0.2:devel/py-chainmap \
		${PYTHON_PKGNAMEPREFIX}future>=0.15.2:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}scandir>=1.3:sysutils/py-scandir

USES=		python

USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	kevans91
GH_TAGNAME=	37f51ef
GH_PROJECT=	OctoPrint

USE_RC_SUBR=	octoprint
SUB_LIST+=	PYTHON=${PYTHON_CMD} \
		HOME=${PREFIX}/octoprint

USERS=		octoprint
GROUPS=		octoprint

NO_ARCH=	yes

post-patch:
	${RM} -rf ${WRKSRC}/src/octoprint/plugins/softwareupdate

.include <bsd.port.mk>
