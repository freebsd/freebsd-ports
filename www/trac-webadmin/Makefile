# New ports collection makefile for: trac-webadmin
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	webadmin
PORTVERSION=	0.1.2.4429
PORTREVISION=	2
CATEGORIES=	www devel python
#MASTER_SITES=	http://trac.edgewall.org/browser/sandbox/webadmin
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracWebAdmin-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Web Administering plugin for trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracWebAdmin
PYDISTUTILS_PKGVERSION=	0.1.2
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
WRKSRC=			${WRKDIR}/${PORTNAME}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${TRACWEBADMIN_EGG}

TRACWEBADMIN_EGG=	TracWebAdmin-${PORTVERSION:R}dev-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		TRACWEBADMIN_EGG=${TRACWEBADMIN_EGG} \
		TRACWEBADMIN_EGG_VER="TracWebAdmin==${PORTVERSION:R}dev"

post-install:
	${LN} -s ${TRACWEBADMIN_EGG} ${PYTHON_SITELIBDIR}/webadmin

# --- trac.ini
# [components]
# webadmin.* = enabled
#
# ---
# % trac-admin /path/to/trac permission add user1 TRAC_ADMIN

.include <bsd.port.mk>
