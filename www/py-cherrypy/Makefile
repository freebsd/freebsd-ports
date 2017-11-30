# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	cherrypy
PORTVERSION=	5.4.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pythonic, object-oriented web development framework

LICENSE=	BSD3CLAUSE

EXAMPLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah>=2.4.4:devel/py-cheetah@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlobject>=1.5.1:databases/py-sqlobject@${FLAVOR}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
SHEBANG_FILES=	cherrypy/cherryd

.include <bsd.port.options.mk>

# handle tutorial separately, and remove cherrypy.process from data_files
# otherwise it confuses build_py.get_outputs() and breaks PYDISTUTILS_AUTOPLIST
post-patch:
	@${REINPLACE_CMD} -e '99,106d' -e '78s/"cherrypy.tutorial",//1' \
		-e '88d' -i.bak ${WRKSRC}/${PYSETUP}

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

.if ${PYTHON_REL} >= 3000    # devel/py-cheetah doesn't yet build with Python 3
.undef EXAMPLES_RUN_DEPENDS
.endif

# The package cherrypy.wsgiserver includes both Python 2 and Python 3 modules,
# so it breaks PYDISTUTILS_AUTOPLIST.
# Instead of defining a cherrypy_build_py.get_outputs() method in setup.py
# we simply remove unwanted modules (see cherrypy_build_py() in setup.py)
post-extract:
.if ${PYTHON_REL} >= 3000
	@(cd ${WRKSRC}/cherrypy && ${RM} _cpcompat_subprocess.py && \
	cd wsgiserver && ${RM} ssl_pyopenssl.py wsgiserver2.py)
.else
	@${RM} ${WRKSRC}/cherrypy/wsgiserver/wsgiserver3.py
.endif

.include <bsd.port.post.mk>
