PORTNAME=	fastjet
DISTVERSION=	3.5.1
CATEGORIES=	science
MASTER_SITES=	https://fastjet.fr/repo/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for jet finding in pp and e+e- collisions
WWW=		https://fastjet.fr/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		fortran gmake libtool shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	fastjet-config.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-allplugins
CONFIGURE_SHELL=	${PREFIX}/bin/bash

LDFLAGS+=	-lexecinfo

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib

OPTIONS_DEFINE=			CGAL PYTHON
OPTIONS_DEFAULT=		CGAL PYTHON
OPTIONS_SUB=			yes

CGAL_DESC=			Build with CGAL computational geometry library
CGAL_USES=			localbase
CGAL_CONFIGURE_ENABLE=		cgal-header-only cgal # cgal is still needed with cgal-header-only contrary to what configure says
CGAL_BUILD_DEPENDS=		cgal>0:math/cgal \
				${LOCALBASE}/include/mpfr.h:math/mpfr
CGAL_LIB_DEPENDS=		libgmp.so:math/gmp

PYTHON_USES=			python
PYTHON_CONFIGURE_ENABLE=	pyext swig
PYTHON_CONFIGURE_ENV=		PYTHON_CONFIG=${PYTHON_CMD}-config
PYTHON_BUILD_DEPENDS=		swig:devel/swig

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

post-install-PYTHON-on:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_fastjet_swig.so.0.0.0

do-test:
	# python tests
.for e in 01-basic 02-area 03-tools 04-multi-event 05-user-info 06-selector 07-recombiner
	@cd ${WRKSRC}/example/python && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./${e}.py
.endfor

.include <bsd.port.mk>
