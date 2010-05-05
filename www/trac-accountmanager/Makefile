# New ports collection makefile for: trac-accountmanager
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	accountmanager
PORTVERSION=	0.2.1.3857
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www devel python
#MASTER_SITES=	http://trac-hacks.org/svn/accountmanagerplugin/trunk/
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracAccountManager-${PORTVERSION}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Account Manager Plugin for trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracAccountManager
PYDISTUTILS_PKGVERSION=	0.2.1dev
WRKSRC=			${WRKDIR}/accountmanagerplugin/trunk

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

pre-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py bdist_egg

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
