PORTNAME=	OpenSPH
DISTVERSION=	0.3.4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and graphical tools for running SPH and N-body simulations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtbb.so:devel/tbb
TEST_DEPENDS=	catch>0:devel/catch

USES=		compiler:c++14-lang eigen:3 qmake qt:5
USE_GITLAB=	yes
USE_WX=		3.1

GL_SITE=	https://gitlab.com
GL_ACCOUNT=	sevecekp
GL_PROJECT=	sph
GL_COMMIT=	3939227cdcbf4e965cfb880b2e5fa3931878317d

QMAKE_SOURCE_PATH=	${WRKSRC}/sph.pro
QMAKE_ARGS=		CONFIG+=release CONFIG+=use_tbb
#QMAKE_ARGS+=		CONFIG+=use_vdb # broken, see https://gitlab.com/sevecekp/sph/-/issues/25

CXXFLAGS+=	-DSPH_CONFIG_SET

TEST_WRKSRC=	${WRKDIR}/test

BINARY_ALIAS=	wx-config=${LOCALBASE}/bin/wxgtk3u-3.1-config

PLIST_FILES=	bin/opensph bin/opensph-cli bin/opensph-info

post-patch:
	@${FIND} ${WRKSRC} -name "*.pro" | ${XARGS} ${REINPLACE_CMD} -e ' \
		s|^target\.path =.*|target\.path = $$$$PREFIX/bin|; \
		s|/usr/include|$$$$PREFIX/include|; \
		s|/usr/lib|$$$$PREFIX/lib| \
		'

do-test:
	@${REINPLACE_CMD} -e 's|Path(.*|Path("${TEST_WRKSRC}");|' ${WRKSRC}/test/utils/Config.h
	@${MKDIR} ${TEST_WRKSRC}
	@cd ${_QMAKE_WRKSRC} && \
		${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS}  \
			${WRKSRC}/test.pro \
			${QMAKE_CONFIGURE_ARGS:?--:} ${QMAKE_CONFIGURE_ARGS}
	@cd ${BUILD_WRKSRC}  && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS}
	@cd ${TEST_WRKSRC}  && \
		${WRKSRC}/test/test

.include <bsd.port.mk>
