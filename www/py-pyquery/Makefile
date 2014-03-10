# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyquery
PORTVERSION=	1.2.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A jquery-like library for python

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:${PORTSDIR}/www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:${PORTSDIR}/www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cssselect>=0.6.1:${PORTSDIR}/www/py-cssselect \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.1:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.2:${PORTSDIR}/www/py-webob

# required by stage: target
MAKE_ENV=	PYTHONUSERBASE=${STAGEDIR}${PYTHONBASE}

OPTIONS_DEFINE=	DOCS

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

# required by stage: target
stage-dir: stage-python-dirs
stage-python-dirs:
	@${MKDIR} ${STAGEDIR}${PYEASYINSTALL_BINDIR} \
	${STAGEDIR}${PYEASYINSTALL_SITELIBDIR}

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif
# required by stage: target
	@(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PYDISTUTILS_BUILD_TARGET+=	build_sphinx -a -E
.endif

# required by stage: target
.undef PYDISTUTILS_INSTALLARGS
PYDISTUTILS_INSTALLARGS=	--always-unzip \
				--install-dir ${STAGEDIR}${PYEASYINSTALL_SITELIBDIR} \
				--multi-version \
				--no-deps \
				--quiet \
				--script-dir ${STAGEDIR}${PYEASYINSTALL_BINDIR} \
				--site-dir ${STAGEDIR}${PYEASYINSTALL_SITELIBDIR} \
				--user \
				${WRKSRC}/dist/${PYEASYINSTALL_EGG}

.include <bsd.port.post.mk>
