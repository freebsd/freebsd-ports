# New ports collection makefile for:	py-cherrypy-devel
# Date created:		2010-07-15
# Whom:			David Brooks <dab@rj45.org>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.2.0.r1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://rj45.org/freebsd/distfiles/${PORTNAME}${PKGNAMESUFFIX}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	dab@rj45.org
COMMENT=	A pythonic, object-oriented web development framework

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}${PORTNAME}-[0-9]*

.if !defined(NOPORTEXAMPLES)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	CherryPy

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/cherrypy/tutorial/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
	${RM} -R ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG}/cherrypy/tutorial

.include <bsd.port.mk>
