# New ports collection makefile for: trac-accountmanager
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	accountmanager
PORTVERSION=	0.1.3.2063
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www devel python
#MASTER_SITES=	http://trac-hacks.org/svn/accountmanagerplugin/0.10/
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracAccountManager-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Account Manager Plugin for trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac \
		${PYTHON_SITELIBDIR}/webadmin/webadmin/__init__.py:${PORTSDIR}/www/trac-webadmin
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	TracAccountManager
PYDISTUTILS_PKGVERSION=	0.1.3
PYDISTUTILS_NOEGGINFO=	yes # XXX convert easy_install support to bsd.python.mk's
WRKSRC=			${WRKDIR}/accountmanagerplugin

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${TRACACCOUNTMANAGER_EGG}

TRACACCOUNTMANAGER_EGG=	TracAccountManager-0.1.3dev-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		TRACACCOUNTMANAGER_EGG=${TRACACCOUNTMANAGER_EGG} \
		TRACACCOUNTMANAGER_EGG_VER="TracAccountManager==0.1.3dev"

# --- trac.ini
# [components]
# acct_mgr.* = enabled
#
# [account-manager]
# password_format = htpasswd
# password_file = /var/trac/trac.htpasswd
#
# --- httpd.conf
# SetEnv PYTHON_EGG_CACHE "/tmp/cache"

.include <bsd.port.mk>
