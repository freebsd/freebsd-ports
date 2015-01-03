# $FreeBSD$

PORTNAME=	math
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	www math python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Support for LaTeX math formulas in wiki pages

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_TEX=	latex
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		python:2
USE_PYTHON=	distutils autoplist

post-install:
	${CAT} ${PKGMESSAGE}

# Maintainter targets below this point

# Retrieve the latest version from SVN and package in a tarball.
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	    svn export http://trac-hacks.org/svn/tracmathplugin/ \
	    ${DISTNAME}
	cd ${WRKDIR} && tar cvf ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
