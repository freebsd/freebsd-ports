PORTNAME=	cadiback
DISTVERSION=	g20240729
PORTREVISION=	1
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CaDiBack BackBone Extractor
WWW=		https://github.com/arminbiere/cadiback

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${NONEXISTENT}:math/cadical:patch
LIB_DEPENDS=	libcadical.so:math/cadical

USES=		gmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	arminbiere
GH_TAGNAME=	789329d

MAKEFILE=	makefile

TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${WRKSRC} && \
		( \
			${ECHO} "#define VERSION \"`cat VERSION`\""; \
			${ECHO} "#define GITID \"${GH_TAGNAME}\""; \
			${ECHO} "#define BUILD \"${CXX} -W\""; \
		) > config.hpp && \
		${CXX} \
			-DNDEBUG \
			${CXXFLAGS} ${LDFLAGS} \
			-I ${WRKSRC_cadical}/src \
			cadiback.cpp \
			-I `${MAKE} -V WRKSRC -C ${PORTSDIR}/math/cadical`/src \
			-l cadical \
			-o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-test:
	@cd ${WRKSRC}/test && \
		./run.sh

.include <bsd.port.mk>
