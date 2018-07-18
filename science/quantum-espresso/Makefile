# $FreeBSD$

PORTNAME=	quantum-espresso
DISTVERSIONPREFIX=	qe-
DISTVERSION=	6.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for research in electronic structure, simulation, optimization

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	fox-xml>0:textproc/fox-xml \
		bash:shells/bash
LIB_DEPENDS=	libmpich.so:net/mpich2 \
		libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake python shebangfix
SHEBANG_FILES=	configure PW/tools/cell2ibrav.py
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	QEF
GH_PROJECT=	q-e
ALL_TARGET=	all

MAKE_ARGS=	TOPDIR=${WRKSRC}
BINARY_ALIAS=	make=gmake cpp=/usr/local/bin/cpp${GCC_DEFAULT}
FFLAGS+=	-x f95-cpp-input
LDFLAGS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgfortran.so -lm

MAKE_JOBS_UNSAFE=	yes # https://github.com/QEF/q-e/issues/9

post-extract:
	@${RM} ${WRKSRC}/archive/lapack-3.6.1.tgz

post-patch:
	@cd ${WRKSRC} && ${MKDIR} FoX && ${LN} -s ${LOCALBASE}/include FoX/finclude

pre-build:
	@${REINPLACE_CMD} -i '' -e ' \
		s|$$(CPP) $$(CPPFLAGS)|$$(CPP) -P -traditional $$(CPPFLAGS)| ; \
		s|LD *=.*|LD=${CC}| ; \
		s|LAPACK_LIBS *=.*|LAPACK_LIBS=-L${LOCALBASE}/lib -llapack -lblas|' \
		${WRKSRC}/make.inc

do-install:
	cd ${WRKSRC}/bin && \
		for e in `ls`; do \
			if [ $$e = "cell2ibrav.x" -o $$e = "iotk" ]; then \
				${INSTALL_SCRIPT} $$e ${STAGEDIR}${PREFIX}/bin; \
			else \
				${INSTALL_PROGRAM} $$e ${STAGEDIR}${PREFIX}/bin; \
			fi; \
		done;

.include <bsd.port.mk>
