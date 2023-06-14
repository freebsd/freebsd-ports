PORTNAME=	cherrypy
PORTVERSION=	18.8.0
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CherryPy-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Pythonic, object-oriented web development framework
WWW=		http://www.cherrypy.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheroot>=8.2.1:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.collections>=4.2.0:devel/py-jaraco.collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=2.1.1:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zclockfile>0:devel/py-zclockfile@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.1.13:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=7.2.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}objgraph>=3.5.0:devel/py-objgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path.py>0:devel/py-path.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.9.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>=1.6.0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-services>=2:devel/py-pytest-services@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-sugar>=0.9.7:devel/py-pytest-sugar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-memcached>=1.59:databases/py-python-memcached@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest
PYTEST_BROKEN_TESTS=	test_0_NormalStateFlow test_8_Ram_Cleanup \
			test_multipart_decoding \
			test_multipart_decoding_bigger_maxrambytes test_pass \
			test_4_File_deletion test_3_Redirect \
			test_threadlocal_garbage
NO_ARCH=	yes
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheetah3>0:devel/py-cheetah3@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlobject>=1.5.1:databases/py-sqlobject@${PY_FLAVOR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/cherrypy/tutorial && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${EXAMPLESDIR} ${EXAMPLESDIR:S,${PREFIX}/,,})

.include <bsd.port.mk>
