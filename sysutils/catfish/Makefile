# Created by: jpaetzel@FreeBSD.org

PORTNAME=	catfish
PORTVERSION=	4.16.4
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GTK search utility

LICENSE=	GPLv3

RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
	pdftotext:graphics/poppler-utils
BUILD_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}

USES=		cpe desktop-file-utils gettext-tools gnome python:3.4+ tar:bz2
USE_PYTHON=	distutils noflavors
USE_GNOME=	gtk30 intltool pygobject3

CPE_VENDOR=	catfish_project

NO_ARCH=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS ZEITGEIST
OPTIONS_DEFAULT=POLKIT
OPTIONS_MULTI=	PRIVILEGES
OPTIONS_MULTI_PRIVILEGES=	POLKIT SUDO

POLKIT_DESC=	Provide Polkit (pkexec) support
POLKIT_RUN_DEPENDS=	pkexec:sysutils/polkit

SUDO_DESC=	Provide sudo support
SUDO_RUN_DEPENDS=	sudo:security/sudo

ZEITGEIST_DESC=	Provide recent search suggestions (broken)
ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.post.mk>
