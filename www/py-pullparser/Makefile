# ex:ts=8
# Ports collection makefile for:	py-pullparser
# Date created:			Apr 29, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pullparser
PORTVERSION=	0.1.0
CATEGORIES=	www python
MASTER_SITES=	http://wwwsearch.sourceforge.net/pullparser/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple "pull API" for HTML parsing

DEPRECATED=     Obsolete and deprecated
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${PULLPARSER_EGG}

PULLPARSER_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PULLPARSER_EGG=${PULLPARSER_EGG} \
		PULLPARSER_EGG_VER="${PORTNAME}==${PORTVERSION}"

.include <bsd.port.mk>
