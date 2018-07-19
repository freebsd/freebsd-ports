# $FreeBSD$

PORTNAME=	quantum-espresso
DISTVERSIONPREFIX=	qe-
DISTVERSION=	6.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.quantum-espresso.org/wp-content/uploads/upf_files/:pp
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

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

MAKE_ARGS=	TOPDIR=${WRKSRC}
BINARY_ALIAS=	make=gmake cpp=/usr/local/bin/cpp${GCC_DEFAULT}
FFLAGS+=	-x f95-cpp-input
LDFLAGS+=	${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgfortran.so -lm

MAKE_JOBS_UNSAFE=	yes # https://github.com/QEF/q-e/issues/9

# pseudo potentials used in calculations
PSEUDO_LIST=	Al.pbe-n-rrkjus_psl.0.1.UPF Al.pbe-n-van.UPF Al.pbe-rrkj.UPF Al.pz-vbc.UPF As.pz-bhs.UPF Au.rel-pz-kjpaw.UPF \
		B.pbe-n-kjpaw_psl.0.1.UPF B.pbe-n-kjpaw_psl.0.1.upf B.pz-vbc.UPF C.pbe-hgh.UPF C.pbe-n-rrkjus_psl.0.1.UPF C.pbe-rrkjus.UPF \
		C.pz-kjpaw.UPF C.pz-rrkjus.UPF C.pz-van_ak.UPF C.pz-vbc.UPF C.tpss-mt.UPF Co.pbe-nd-rrkjus.UPF Cu.pbe-kjpaw.UPF \
		Cu.pz-d-rrkjus.UPF Fe.pz-nd-rrkjus.UPF Fe.rel-pbe-kjpaw.UPF Fe.rel-pbe-spn-rrkjus_psl.0.2.1.UPF H.blyp-vbc.UPF H.pbe-kjpaw.UPF \
		H.pbe-rrkjus.UPF H.pbe-van_ak.UPF H.pz-kjpaw.UPF H.pz-vbc.UPF H.tpss-mt.UPF Mg.pbe-n-kjpaw_psl.0.3.0.upf \
		Mg.pz-n-vbc.UPF N.blyp-mt.UPF N.pbe-kjpaw.UPF N.pbe-n-kjpaw_psl.0.1.UPF N.pz-vbc.UPF Ni.pbe-nd-rrkjus.UPF Ni.pz-nd-rrkjus.UPF \
		O.blyp-mt.UPF O.pbe-hgh.UPF O.pbe-kjpaw.UPF O.pbe-rrkjus.UPF O.pbe-van_ak.UPF O.pz-rrkjus.UPF O.pz-van_ak.UPF \
		Pb.pz-d-van.UPF Pt.rel-pz-n-rrkjus.UPF Si.pbe-rrkj.UPF \
		Si.pz-vbc.UPF Ti.pz-sp-van_ak.UPF Zn.pbe-d-hgh.UPF

.for pp in ${PSEUDO_LIST}
DISTFILES+=	${pp}:pp
.endfor

post-extract:
	@${RM} ${WRKSRC}/archive/lapack-3.6.1.tgz
	@cd ${WRKSRC} && ${MKDIR} FoX && ${LN} -s ${LOCALBASE}/include FoX/finclude

pre-build:
	@${REINPLACE_CMD} -i '' -e ' \
		s|$$(CPP) $$(CPPFLAGS)|$$(CPP) -P -traditional $$(CPPFLAGS)| ; \
		s|LD *=.*|LD=${CC}| ; \
		s|LAPACK_LIBS *=.*|LAPACK_LIBS=-L${LOCALBASE}/lib -llapack -lblas|' \
		${WRKSRC}/make.inc

post-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} pseudo ${STAGEDIR}${DATADIR}
.for pp in ${PSEUDO_LIST}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${pp} ${STAGEDIR}${DATADIR}/pseudo
.endfor

run-examples: build
.for c in PP PW PWCOND PHonon
	@cd ${WRKSRC}/$c/examples && PREFIX=${STAGEDIR}${PREFIX} ./run_all_examples
.endfor

.include <bsd.port.mk>
