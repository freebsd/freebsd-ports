# $FreeBSD$

PORTNAME=	math
PORTVERSION=	0.1
PORTREVISION=	7
CATEGORIES=	www math python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Support for LaTeX math formulas in wiki pages

RUN_DEPENDS=	tracd:www/trac

USE_TEX=	latex
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		python:2
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

# Maintainter targets below this point

# Retrieve the latest version from SVN and package in a tarball.
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	    svn export http://trac-hacks.org/svn/tracmathplugin/ \
	    ${DISTNAME}
	cd ${WRKDIR} && tar cvf ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include <bsd.port.mk>
