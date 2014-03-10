# $FreeBSD$

PORTNAME=	pandas
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	math devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	Flexible, high-performance data analysis in Python

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
TEST_DEPENDS=	${RUN_DEPENDS} \
		nosetests:${PORTSDIR}/devel/py-nose \
		cython:${PORTSDIR}/lang/cython \
		${PYTHON_PKGNAMEPREFIX}boto>0:${PORTSDIR}/devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}tables>0:${PORTSDIR}/devel/py-tables \
		${PYTHON_PKGNAMEPREFIX}bottleneck>0:${PORTSDIR}/math/py-bottleneck \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}numexpr>0:${PORTSDIR}/math/py-numexpr \
		${PYTHON_PKGNAMEPREFIX}scipy>0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:${PORTSDIR}/textproc/py-openpyxl \
		${PYTHON_PKGNAMEPREFIX}xlrd>0:${PORTSDIR}/textproc/py-xlrd \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:${PORTSDIR}/textproc/py-xlwt \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib
# Note: we cannot include math/py-statsmodels in TEST_DEPENDS because it
# depends upon us for BUILD and RUN.

SUB_FILES=	pkg-message

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# Uncomment the following line to enable regression-test
# on a headless (X11-less) host (eg: RedPorts)
#USES=		display:regression-test

XUNITFILE=	${WRKDIR}/nosetests.xml
NOSE_ENV=	http_proxy=${HTTP_PROXY}
NOSE_ARGS=	${PORTNAME} --exe --with-xunit --xunit-file=${XUNITFILE}

regression-test: build
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYSETUP} build_ext --inplace && \
		${PYTHON_CMD} -c 'import pandas.util.print_versions as pv; pv.show_versions()' && \
		( ${SETENV} ${NOSE_ENV} nosetests ${NOSE_ARGS} || ${TRUE} ) && \
		${PYTHON_CMD} ${SCRIPTDIR}/print_skipped.py ${XUNITFILE}
	)

.include <bsd.port.mk>
