# New ports collection makefile for: trac-mercurial
# Date created:                      January 23, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;:L}
PORTVERSION=	${TRAC_VERSION}.${PLUGIN_VERSION}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
DIST_SUBDIR=	trac

MAINTAINER=	brooks@freebsd.org
COMMENT=	A trac plugin providing a downloads section

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

TRAC_VERSION=	0.11
PLUGIN_VERSION=	0.2

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracDownloads
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PLUGIN_VERSION}-py${PYTHON_VER}.egg

.if defined(BOOTSTRAP)
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export http://trac-hacks.org/svn/downloadsplugin/0.11/ ${WRKSRC}
	${MKDIR} ${_DISTDIR}
	cd ${WRKDIR} && \
	    tar cfvz ${_DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include <bsd.port.mk>
