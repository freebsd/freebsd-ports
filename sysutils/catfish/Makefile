PORTNAME=	catfish
PORTVERSION=	4.20.1
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GTK search utility
WWW=		https://www.bluesabre.org/projects/catfish/

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		pdftotext:graphics/poppler-utils

USES=		cpe desktop-file-utils gettext-tools gnome meson pkgconfig \
		python shebangfix tar:xz xfce
CPE_VENDOR=	catfish_project
USE_GNOME=	gdkpixbuf gtk30 pygobject3
USE_XFCE=	xfconf
SHEBANG_FILES=	bin/catfish
BINARY_ALIAS=	python3=${PYTHON_CMD}

NO_ARCH=	yes

PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=			DOCS ZEITGEIST
OPTIONS_DEFAULT=		POLKIT
OPTIONS_MULTI=			PRIVILEGES
OPTIONS_MULTI_PRIVILEGES=	POLKIT SUDO

POLKIT_DESC=	Provide Polkit (pkexec) support
SUDO_DESC=	Provide sudo support
ZEITGEIST_DESC=	Provide recent search suggestions (broken)

POLKIT_RUN_DEPENDS=	pkexec:sysutils/polkit

ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist

SUDO_USES=	sudo

.include <bsd.port.mk>
