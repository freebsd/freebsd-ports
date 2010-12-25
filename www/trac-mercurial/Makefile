# New ports collection makefile for: trac-mercurial
# Date created:                      January 23, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;:L}
PORTVERSION=	0.12.0.1
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/pgollucci
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
DIST_SUBDIR=	trac

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A plugin to use Mercurial instead of Subversion in Trac

RUN_DEPENDS+=	hg:${PORTSDIR}/devel/mercurial \
		tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracMercurial
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-0.12.0.23dev-py${PYTHON_VER}.egg

.if defined(BOOTSTRAP)
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export http://svn.edgewall.org/repos/trac/plugins/0.12/mercurial-plugin ${WRKSRC}
	${MKDIR} ${_DISTDIR}
	cd ${WRKDIR} && \
	    tar cfvz ${_DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include <bsd.port.mk>
