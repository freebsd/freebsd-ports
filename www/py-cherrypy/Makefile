# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.2.2
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

.if !defined(NOPORTEXAMPLES)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	CherryPy

PLIST_SUB=	PY2=${PY2} PYMAJORVER=${PYMAJORVER}

PYMAJORVER=	${PYTHON_VER:R}

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/${PORTNAME} && ${COPYTREE_SHARE} tutorial ${EXAMPLESDIR}
.endif
	${RM} -R ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/${PORTNAME}/tutorial
.if ${PYMAJORVER} == 2
PY2=''
.else
PY2='@comment '
.endif

.include <bsd.port.post.mk>
