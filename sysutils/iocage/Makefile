PORTNAME=	iocage
PORTVERSION=	1.11
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

# Pull in PR #61 to unbreak default route detection on CURRENT
PATCH_SITES=    https://github.com/freebsd/iocage/commit/
PATCHFILES=	2120a86d1d4fd3d383a3f0bddfc1e92eb5a7d2e7.patch:-p1

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python3
WWW=		https://github.com/freebsd/iocage

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>0:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.7:textproc/py-texttable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>0:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libzfs>=1.0.2:filesystems/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
USE_PYTHON=	autoplist distutils

CONFLICTS=	py*[0-9]-iocage py*-iocage-devel
NO_ARCH=	yes

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/PKG-INFO \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/SOURCES.txt \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/dependency_links.txt \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/entry_points.txt \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/requires.txt \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib-${PORTVERSION}-py${PYTHON_VER}.egg-info/top_level.txt \
		${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}_lib/plugin_manifest.json

OPTIONS_DEFAULT=	GIT
OPTIONS_RADIO=	GIT_PACKAGE
OPTIONS_RADIO_GIT_PACKAGE=	GIT GIT_LITE

GIT_DESC=	depend on devel/git
GIT_LITE_DESC=	depend on lite flavor of devel/git (bare minimum git experience)

GIT_RUN_DEPENDS=git:devel/git
GIT_LITE_RUN_DEPENDS=git:devel/git@lite

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
