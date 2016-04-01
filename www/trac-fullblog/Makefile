# $FreeBSD$

PORTNAME=	fullblog
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	LOCAL/brooks
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
DIST_SUBDIR=	trac

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin that provides a project Blog

RUN_DEPENDS+=	htmldoc:textproc/htmldoc \
		tracd:www/trac

USES=		python:2
USE_PYTHON=	distutils autoplist

.if defined(BOOTSTRAP)
do-fetch:
	${MKDIR} ${WRKDIR}
	svn export http://trac-hacks.org/svn/fullblogplugin/0.11/ ${WRKSRC}
	${MKDIR} ${_DISTDIR}
	cd ${WRKDIR} && \
	    tar cfvz ${_DISTDIR}/${DISTNAME}.tar.gz ${DISTNAME}
.endif

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
