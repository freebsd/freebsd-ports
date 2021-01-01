# $FreeBSD$

PORTNAME=	discussion
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Discussion forum plugin for Trac

RUN_DEPENDS=	tracd:www/trac \
		trac-TracSpamFilter>=0.2.1:www/trac-spam-filter

USES=		python:2.7
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

# Maintainter targets below this point

# Retrieve the latest version from SVN and package in a tarball.
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:devel/subversion
do-fetch:
	${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && \
	    svn export http://trac-hacks.org/svn/discussionplugin/0.11/ \
	    ${DISTNAME}
	cd ${WRKDIR} && ${TAR} cvf ${DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include <bsd.port.mk>
