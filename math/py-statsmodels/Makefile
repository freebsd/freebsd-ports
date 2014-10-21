# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	statsmodels
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@chaot.net
COMMENT=	Complement to SciPy for statistical computations

LICENSE=	BSD

BROKEN=		Fails to build

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}pandas>0:${PORTSDIR}/math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}patsy>0:${PORTSDIR}/math/py-patsy
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}pandas>0:${PORTSDIR}/math/py-pandas \
		${PYTHON_PKGNAMEPREFIX}patsy>0:${PORTSDIR}/math/py-patsy

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/doc/py-${PORTNAME}

USES=		python
USE_PYTHON=	distutils py3kplist noegginfo
PLIST_SUB=	PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}
PORTDOCS=	* .buildinfo
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
	${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
	ipython:${PORTSDIR}/devel/ipython

PYDISTUTILS_BUILD_TARGET+=	build_sphinx
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/_smoothers_lowess.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/nonparametric/linbin.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/tsa/kalmanf/kalman_loglike.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${WRKSRC}/README_l1.txt ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
