PORTNAME=	catfish
PORTVERSION=	4.20.0
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GTK search utility
WWW=		https://www.bluesabre.org/projects/catfish/

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		pdftotext:graphics/poppler-utils
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}

USES=		cpe desktop-file-utils gettext-tools gnome meson python tar:bz2
USE_GNOME=	gtk30 pygobject3

CPE_VENDOR=	catfish_project

NO_ARCH=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=	DOCS ZEITGEIST
OPTIONS_DEFAULT=POLKIT
OPTIONS_MULTI=	PRIVILEGES
OPTIONS_MULTI_PRIVILEGES=	POLKIT SUDO

POLKIT_DESC=	Provide Polkit (pkexec) support
SUDO_DESC=	Provide sudo support
ZEITGEIST_DESC=	Provide recent search suggestions (broken)

POLKIT_RUN_DEPENDS=	pkexec:sysutils/polkit

SUDO_RUN_DEPENDS=	sudo:security/sudo

ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist

.include <bsd.port.mk>
