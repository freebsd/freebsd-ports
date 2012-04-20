# New ports collection makefile for: trac-tags
# Date created:                      December 28 2006
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	tags
DISTVERSION=	0.7.r${SVN_REV}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-
DIST_SUBDIR=	trac

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A generic tags frontend for trac

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	TracTags
EGGVERSION=	${PORTVERSION:C/\.r.*/dev/}
PLIST_SUB+=	EGGVERSION=${EGGVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.pre.mk>

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
LANG=           "C"
SVN_REV!=       svn info http://trac-hacks.org/svn/tagsplugin/trunk/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+= svn:${PORTSDIR}/devel/subversion

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} \
	    http://trac-hacks.org/svn/tagsplugin/trunk/ ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
	echo "SVN_REV=  ${SVN_REV}" > ${MASTERDIR}/Makefile.svn_rev
.if ${USER} == brooks
	scp ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif

do-build:
	@${DO_NADA}

.include <bsd.port.post.mk>
