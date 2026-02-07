PORTNAME=	iocage-devel
PORTVERSION=	1.11.20250711
PORTEPOCH=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python3
WWW=		https://github.com/freebsd/iocage

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>0:devel/py-coloredlogs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=2.1.10:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libzfs>=1.0.2:filesystems/py-libzfs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.7:textproc/py-texttable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py-tqdm@${PY_FLAVOR} \
		ca_root_nss>0:security/ca_root_nss

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	iocage
GH_TAGNAME=	b519cc3d7cf94b532a89fca698fa724805538a2f

USE_PYTHON=	autoplist distutils

CONFLICTS=	py*[0-9]-iocage py*-iocage-devel
NO_ARCH=	yes

_IOCAGE_LIB_VERSION=	1.11
PLIST_FILES=		${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/dependency_links.txt \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/entry_points.txt \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/PKG-INFO \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/requires.txt \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/SOURCES.txt \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib-${_IOCAGE_LIB_VERSION}-py${PYTHON_VER}.egg-info/top_level.txt \
			${PYTHON_SITELIBDIR}/${PORTNAME:S/-devel//g}_lib/plugin_manifest.json

OPTIONS_DEFAULT=		GIT
OPTIONS_RADIO=			GIT_PACKAGE
OPTIONS_RADIO_GIT_PACKAGE=	GIT GIT_LITE

GIT_DESC=	depend on devel/git
GIT_LITE_DESC=	depend on lite flavor of devel/git (bare minimum git experience)

GIT_RUN_DEPENDS=	git:devel/git
GIT_LITE_RUN_DEPENDS=	git:devel/git@lite

.include <bsd.port.mk>
