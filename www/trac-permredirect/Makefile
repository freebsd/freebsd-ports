# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	permredirect
PORTVERSION=	2.0.${REV}
CATEGORIES=	www devel python
MASTER_SITES=	http://trac-hacks.org/changeset/${REV}/${PORTNAME}plugin/${BRANCH}?old_path=/&format=zip&filename= \
		http://files.roorback.net/
PKGNAMEPREFIX=	trac-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Redirect users to the login screen on PermissionError

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
BRANCH=			0.11
REV=			3593
USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracPermRedirect
PYDISTUTILS_PKGVERSION=	2.0
WRKSRC=			${WRKDIR}/${PORTNAME}plugin/${BRANCH}

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

pre-build:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py bdist_egg

.include <bsd.port.mk>
