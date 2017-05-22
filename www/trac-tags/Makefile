# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	tags
DISTVERSION=	0.7.r${SVN_REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DIST_SUBDIR=	trac

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Generic tags frontend for trac

RUN_DEPENDS=	tracd:www/trac

USES=		python:2 tar:bzip2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if !defined(SVN_REV)
.if defined(BOOTSTRAP)
SVN_REV!=	svn info http://trac-hacks.org/svn/tagsplugin/trunk/ | ${GREP} Revision | cut -d' ' -f2
.else
.include "Makefile.svn_rev"
.endif
.endif

.if defined(BOOTSTRAP) || defined(SVN_FETCH)
FETCH_DEPENDS+=	svn:devel/subversion

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

.include <bsd.port.post.mk>
