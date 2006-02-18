# New ports collection makefile for: trac-accountmanager
# Date created:                      17 Feb 2006
# Whom:                              kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	accountmanagerplugin
PORTVERSION=	0.9
CATEGORIES=	www devel python
#MASTER_SITES=	http://trac-hacks.org/download/accountmanagerplugin.zip
MASTER_SITES=	http://dist.bsdlab.org/
PKGNAMEPREFIX=	trac-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Account Manager Plugin for trac

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTVERSION}
PLIST_SUB=	VERSION=0.1.2 PYVER=${PYTHON_VERSION:S/python//} SED=${SED}

do-build:
	@${DO_NADA}

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
