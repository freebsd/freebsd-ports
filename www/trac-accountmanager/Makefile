# New ports collection makefile for: trac-accountmanager
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	accountmanager
PORTVERSION=	0.4.${REV}
PORTEPOCH=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://trac-hacks.org/changeset/${REV}/accountmanagerplugin/trunk?old_path=/&format=zip&filename=
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	trac-
DIST_SUBDIR=	trac

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Account Manager Plugin for trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			11722
USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracAccountManager
PYDISTUTILS_PKGVERSION=	0.4dev
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
