PORTNAME=	nlopt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	math

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Nonlinear optimization library
WWW=		https://nlopt.readthedocs.io/en/latest/

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv6=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory
BROKEN_armv7=	fails to package: Unable to access file site-packages/_nlopt.a:No such file or directory

FLAVORS=	full minimal

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	stevengj
USE_LDCONFIG=	yes

.if ${FLAVOR:U} == minimal
PKGNAMESUFFIX=	-${FLAVOR}
CMAKE_OFF=	NLOPT_GUILE NLOPT_PYTHON NLOPT_SWIG
CONFLICTS_INSTALL=	${PORTNAME}
.else
USES+=		guile:3.0,alias localbase pkgconfig python
BUILD_DEPENDS=	swig:devel/swig ${PYNUMPY}
# Because guile-config-3.0 crashes, nlopt avoids this by using
# files/patch-cmake_FindGuile.cmake and setting GUILE_EXECUTABLE
# and GUILE_CONFIG_EXECUTABLE
MAKE_ENV+=	GUILE_EXECUTABLE=${PREFIX}/bin/guile3 \
		GUILE_CONFIG_EXECUTABLE=${PREFIX}/bin/guile-config-3
RUN_DEPENDS=	${PYNUMPY}
CONFLICTS_INSTALL=	${PORTNAME}-minimal
PLIST_FILES+=	lib/guile/3.0/extensions/nlopt_guile.so \
		${PYTHON_SITELIBDIR}/_nlopt%%PYTHON_EXT_SUFFIX%%.so \
		${PYTHON_SITELIBDIR}/nlopt.py \
		${GUILE_SITE_DIR}/nlopt.scm
.endif

.include <bsd.port.mk>
