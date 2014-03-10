# $FreeBSD$

PORTNAME=	accountmanager
PORTVERSION=	0.5.${REV}
PORTEPOCH=	1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://trac-hacks.org/changeset/${REV}/accountmanagerplugin/trunk?old_path=/&format=zip&filename=
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMEPREFIX=	trac-
DIST_SUBDIR=	trac

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Account Manager Plugin for trac

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			12583
USES=			zip
USE_PYTHON=		2
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracAccountManager
PYDISTUTILS_PKGVERSION=	0.5dev
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
WRKSRC=			${WRKDIR}/accountmanagerplugin/trunk

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
