# Created by: jpaetzel@FreeBSD.org
# $FreeBSD$

PORTNAME=	catfish
PORTVERSION=	1.4.11
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GTK search utility

LICENSE=	GPLv3

RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		desktop-file-utils gettext-tools gnome python:2.7 tar:bz2
USE_PYTHON=	distutils
USE_GNOME=	gtk30 intltool pygobject3

NO_ARCH=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS ZEITGEIST
OPTIONS_DEFAULT=ZEITGEIST POLKIT
OPTIONS_MULTI=	PRIVILEGES
OPTIONS_MULTI_PRIVILEGES=	POLKIT SUDO

POLKIT_DESC=	Provide Polkit (pkexec) support
POLKIT_RUN_DEPENDS=	pkexec:sysutils/polkit

SUDO_DESC=	Provide sudo support
SUDO_RUN_DEPENDS=	sudo:security/sudo

ZEITGEIST_DESC=	Provide recent search suggestions
ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/catfish.1 ${STAGEDIR}${PREFIX}/man/man1/catfish.1
	(cd ${STAGEDIR}${PREFIX}/share && ${RMDIR} -p man/man1)
	${GZIP} ${STAGEDIR}${PREFIX}/man/man1/catfish.1

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.post.mk>
