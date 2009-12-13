# New ports collection makefile for: trac-fullblog
# Date created:                      January 9, 2009
# Whom:                              Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	${PYDISTUTILS_PKGNAME:S;^Trac;;S;Plugin$;;:L}
PORTVERSION=	0.1
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	brooks@freebsd.org
COMMENT=	This plugin provides a project Blog

RUN_DEPENDS+=	htmldoc:${PORTSDIR}/textproc/htmldoc \
		tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.5+
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracFullBlogPlugin
WRKSRC=		${WRKDIR}/${PORTNAME}plugin
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER}

EGG_PATH=	${PYTHONPREFIX_SITELIBDIR}/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

do-build:
	@${DO_NADA}

build-plist:
	@${CAT} /dev/null > ${PLIST}
	${FIND} ${EGG_PATH} -type f | \
	    ${SED} -e 's|${EGG_PATH}|%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-%%PORTVERSION%%-py%%PYTHON_VER%%.egg|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${EGG_PATH} -type d | \
	    ${SED} -e 's|${EGG_PATH}|@dirrm %%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-%%PORTVERSION%%-py%%PYTHON_VER%%.egg|' | \
	    ${SORT} -r >> ${PLIST}

.include <bsd.port.mk>
