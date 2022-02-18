# Created by: keith@FreeBSD.org

PORTNAME=	gap
DISTVERSION=	4.11.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/gap-system/gap/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	System for computational discrete algebra

LICENSE=	GPLv2+

BROKEN_aarch64=		fails to link: undefined reference to SyAllocBags
BROKEN_riscv64=		fails to link: undefined reference to SyAllocBags

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf:build gmake libtool localbase perl5 shebangfix	\
		readline
SHEBANG_FILES=	.
USE_PERL5=	run

OPTIONS_DEFINE=	ADDPACK MANU
OPTIONS_DEFAULT=ADDPACK
OPTIONS_SUB=	yes
ADDPACK_DESC=	Additional packages typically "expected" out-of-the-box
ADDPACK_VARS=	ADD_PACK="${ADDPACK}"
MANU_DESC=	HTML and PDF manuals
MANU_USE=	TEX=latex:build,formats,web2c
MANU_VARS=	DOC_TARGET=doc

GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	all ${DOC_TARGET}
INSTALL_TARGET=	install-headers install-libgap
USE_LDCONFIG=	yes
PORTDATA=	doc/*

MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	ALNUTH_VER=3.1.2 AUTPGRP_VER=1.10.2 CRISP_VER=1.4.5 \
		CTBLLIB_VER=1.3.1 FACT_INT_VER=1.6.3 GAP_DOC_VER=1.6.4 \
		HELP_VER=3.5 IRREDSOL_VER=1.4.1 LAGUNA_VER=3.9.3 \
		POLENTA_VER=1.3.9 POLYCYCLIC_VER=2.16 PRIMGRP_VER=3.4.1 \
		RESCLASSES_VER=4.7.2 SOPHUS_VER=1.24 SMALL_GRP_VER=1.4.2 \
		TOMLIB_VER=1.2.9

# The minimal packages GAP needs to run (do not need compilation)
MINPACK=	GAPDoc- HeLP- primgrp- SmallGrp- transgrp
ADDPACK=	atlasrep autpgrp- alnuth- crisp- ctbllib FactInt- fga	\
		irredsol- laguna- polenta- polycyclic- resclasses-	\
		sophus- tomlib-

ACLOCVER=	1.16	# Truncated version of aclocal / automake

.include <bsd.port.options.mk>

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	${REINPLACE_CMD} -i .c++20 's/-I/-iquote/' \
		${WRKSRC}/pkg/*/Makefile.in
.for f in aclocal.m4 configure
	${FIND} ${WRKSRC} -name ${f} | ${XARGS} ${REINPLACE_CMD} -i ''	\
		-e "s|am__api_version='1.15'|am__api_version='${ACLOCVER}'|"
.endfor

post-build:
	@cd ${WRKSRC}/pkg/simpcomp && \
		${SETENV} ${CONFIGURE_ENV} ${SH} configure \
			${CONFIGURE_ARGS:N--with-*} && \
		${MAKE} ${MAKEFLAGS} && \
		${MAKE} ${MAKEFLAGS} install-strip && \
		${RM} bistellar

post-install:
	# additional header
	${INSTALL_DATA} ${WRKSRC}/gen/config.h ${STAGEDIR}${PREFIX}/include/gap
	# install gap binary
	${INSTALL_PROGRAM} ${WRKSRC}/gap ${STAGEDIR}${PREFIX}/bin/gap-bin
	# strip
	cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/gap-bin lib/libgap.so.0.0.0
	# install gac executable
	${INSTALL_SCRIPT} ${WRKSRC}/gac ${STAGEDIR}${PREFIX}/bin/gac
	${REINPLACE_CMD} -i '' -e ' \
		s|^\. "$${abs_top_builddir}/sysinfo.gap"|. "${DATADIR}/sysinfo.gap"|; \
		s|^abs_top_builddir=.*|abs_top_builddir="${DATADIR}/min-builddir"|; \
		s|^abs_top_srcdir=.*|abs_top_srcdir="${DATADIR}/min-srcdir"| \
		' ${STAGEDIR}${PREFIX}/bin/gac
	# prepare and install wrapper
	@${CAT} ${WRKSRC}/bin/gap.sh | ${SED} -e ' \
		s:${WRKSRC}:${GAP_LIBDIR}:; \
		s:GAP_DIR=.*:GAP_DIR=${DATADIR}:; \
		s:GAP_EXE=.*:GAP_EXE=${PREFIX}/bin/gap-bin:; \
		/^exec/s:/gap::; \
		' > ${WRKSRC}/bin/gap
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gap ${STAGEDIR}${PREFIX}/bin
	# min-builddir and min-srcdir
	${MKDIR} ${STAGEDIR}${DATADIR}/min-builddir ${STAGEDIR}${DATADIR}/min-srcdir
	${INSTALL_SCRIPT} ${WRKSRC}/libtool ${STAGEDIR}${DATADIR}/min-builddir
	${RLN} ${STAGEDIR}${PREFIX}/bin/gap ${STAGEDIR}${DATADIR}/min-builddir/gap
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} obj ${STAGEDIR}${DATADIR}/min-builddir/
	# install packages
	${MKDIR} ${STAGEDIR}${DATADIR}/pkg
.for f in doc etc gen grp lib tst sysinfo.gap
	${CP} -R ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/
.endfor
.for p in ${MINPACK} ${ADD_PACK}
	cd ${WRKSRC}/pkg && ${CP} -R $$(ls -d ${p}*) ${STAGEDIR}${DATADIR}/pkg/
.endfor
	# correct paths in sysinfo.gap
	${REINPLACE_CMD} -i '' -e ' \
		s|^GAP_BIN_DIR=.*|GAP_BIN_DIR="${PREFIX}/bin"|; \
		s|^GAP_LIB_DIR=.*|GAP_LIB_DIR="${PREFIX}/lib"|; \
		s| -isystem ${PREFIX}/include |&-I${PREFIX}/include/gap |; \
		' ${STAGEDIR}${DATADIR}/sysinfo.gap

do-test:
	@cd ${WRKSRC} && ./gap ${FILESDIR}/test.g

.include <bsd.port.mk>
