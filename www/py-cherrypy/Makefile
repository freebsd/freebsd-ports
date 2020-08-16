# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	cherrypy
PORTVERSION=	17.4.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pythonic, object-oriented web development framework

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}

EXAMPLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlobject>=1.5.1:databases/py-sqlobject@${PY_FLAVOR}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cheroot>=6.2.4:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=2.1.1:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zclockfile>0:devel/py-zclockfile@${PY_FLAVOR}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

USES=		python
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/cherrypy/tutorial && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${EXAMPLESDIR} ${EXAMPLESDIR:S,${PREFIX}/,,})
.endif

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}more-itertools5>0:devel/py-more-itertools5@${PY_FLAVOR}
EXAMPLES_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.4.4:devel/py-cheetah@${PY_FLAVOR}
.else
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR}
EXAMPLES_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
