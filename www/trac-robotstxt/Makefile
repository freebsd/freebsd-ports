# New ports collection makefile for:	trac-robotxt
# Date created:		03. 23, 2007
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	robotxt
PORTVERSION=	1.0.1
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracRobotsTxt-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Allows simple management of a robots.txt.

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${TRACROBO_EGG}
PYDISTUTILS_NOEGGINFO=		yes

TRACROBO_EGG=	TracRobotsTxt-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		TRACROBO_EGG=${TRACROBO_EGG} \
		TRACROBO_EGG_VER="TracRobotsTxt==${PORTVERSION}"

.include <bsd.port.mk>
