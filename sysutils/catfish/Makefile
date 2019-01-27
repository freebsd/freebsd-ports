# Created by: jpaetzel@FreeBSD.org
# $FreeBSD$

PORTNAME=	catfish
PORTVERSION=	1.4.7
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/src/apps/${PORTNAME:tl}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	GTK search utility

LICENSE=	GPLv3

RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
	gksu:sysutils/gksu
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		desktop-file-utils gettext-tools gnome python:2.7 tar:bz2
NO_ARCH=	yes
USE_PYTHON=	distutils
USE_GNOME=	gtk30 intltool pygobject3

OPTIONS_DEFINE=	DOCS ZEITGEIST
OPTIONS_DEFAULT=ZEITGEIST

ZEITGEIST_DESC=	Provide recent search suggestions
ZEITGEIST_LIB_DEPENDS=	libzeitgeist-2.0.so:sysutils/zeitgeist

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} --root=${STAGEDIR}

.include <bsd.port.post.mk>
