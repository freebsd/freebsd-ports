# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	permredirect
PORTVERSION=	3.0
CATEGORIES=	www devel python
MASTER_SITES=	http://trac-hacks.org/changeset/${REV}/${PORTNAME}plugin/tags/${PORTVERSION}?old_path=${PORTNAME}plugin&format=zip&filename= \
		LOCAL/gblach/
PKGNAMEPREFIX=	trac-
DIST_SUBDIR=	trac

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Redirect users to the login screen on PermissionError

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
REV=			13353
USES=			zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracPermRedirect
PYDISTUTILS_PKGVERSION=	${PORTVERSION}
WRKSRC=			${WRKDIR}/${PORTNAME}plugin/tags/${PORTVERSION}

PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
