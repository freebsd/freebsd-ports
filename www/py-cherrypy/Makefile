# New ports collection makefile for:	py-cherrypy
# Date created:		2006-01-11
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	cherrypy
PORTVERSION=	3.2.0
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://download.cherrypy.org/cherrypy/${PORTVERSION}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A pythonic, object-oriented web development framework

#RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.0.0:${PORTSDIR}/devel/py-nose
.if !defined(NOPORTEXAMPLES)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	cherryd.1
.endif

PLIST_SUB=	PY2=${PY2}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	CherryPy

PYVER=	${PYTHON_PKGNAMEPREFIX:C/[0-9]-$//1}
PY2FILES=	native-server.ini fastcgi.conf

.include <bsd.port.pre.mk>

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN1} ${MANPREFIX}/man/man1
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/${PORTNAME} && ${COPYTREE_SHARE} tutorial ${EXAMPLESDIR}
.endif
	${RM} -R ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/${PORTNAME}/tutorial
.if ${PYVER} == py2
	cd ${WRKSRC}/${PYVER}/${PORTNAME}/test && ${INSTALL_DATA} ${PY2FILES} ${PYTHONPREFIX_SITELIBDIR}/${PYEASYINSTALL_EGG}/cherrypy/test/
PY2=''
.else
PY2=@comment
.endif

.include <bsd.port.post.mk>
