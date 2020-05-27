# Created by: keith@FreeBSD.org
# $FreeBSD$

PORTNAME=	gap
PORTVERSION=	4.11.0
CATEGORIES=	math
MASTER_SITES=	https://files.gap-system.org/${PORTNAME}-${PORTVERSION:R}/${EXTRACT_SUFX:C/\.//}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	System for computational discrete algebra

LICENSE=	GPLv2+

BROKEN_aarch64=		fails to link: undefined reference to SyAllocBags

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf:build gmake libtool localbase perl5 shebangfix	\
		readline tar:bzip2
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

# The minimal packages GAP needs to run (do not need compilation)
MINPACK=	GAPDoc- HeLP- primgrp- SmallGrp- transgrp
ADDPACK=	atlasrep autpgrp- alnuth- crisp- ctbllib FactInt- fga	\
		irredsol- laguna- polenta- polycyclic- resclasses-	\
		sophus- tomlib-

ACLOCVER=	1.16	# Truncated version of aclocal / automake
BASH2FIX=	pkg/AGT-0.1/GNUmakefile \
		pkg/AGT-0.1/gac

.include <bsd.port.options.mk>

pre-configure:
# Avoid conflict with C++20 <version> by ignoring <...> under WRKSRC
	${REINPLACE_CMD} -i .c++20 's/-I/-iquote/' \
		${WRKSRC}/pkg/*/Makefile.in
.for f in ${BASH2FIX}
	${REINPLACE_CMD} -i '' -e 's|/bin/bash|${LOCALBASE}/bin/bash|'	\
		${WRKSRC}/${f}
.endfor
.for f in aclocal.m4 configure
	${FIND} ${WRKSRC} -name ${f} | ${XARGS} ${REINPLACE_CMD} -i ''	\
		-e "s|am__api_version='1.15'|am__api_version='${ACLOCVER}'|"
.endfor

post-build:
	cd ${WRKSRC}/pkg/simpcomp && \
	    ${SETENV} ${CONFIGURE_ENV} ${SH} configure \
		${CONFIGURE_ARGS:N--with-*} && \
	    ${MAKE} ${MAKEFLAGS} && \
	    ${MAKE} ${MAKEFLAGS} install-strip && \
	    ${RM} bistellar

post-install:
	${INSTALL_DATA} ${WRKSRC}/gen/config.h ${STAGEDIR}${PREFIX}/include/gap
	(cd ${WRKSRC} &&	\
	./libtool --mode=install install gap ${STAGEDIR}${PREFIX}/bin/gap-bin)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gap-bin
	(cd ${WRKSRC} &&	\
	./libtool --mode=install install gac ${STAGEDIR}${PREFIX}/bin/gac)
	${SED} -e "s:${WRKSRC}:${GAP_LIBDIR}:" ${WRKSRC}/bin/gap.sh \
		> ${WRKSRC}/bin/gap
	${SED} -e "s:GAP_DIR=.*:GAP_DIR=${DATADIR}:" \
		-e "s:GAP_EXE=.*:GAP_EXE=${PREFIX}/bin/gap-bin:" \
		-e "/^exec/s:/gap::" ${WRKSRC}/bin/gap.sh > ${WRKSRC}/bin/gap
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gap ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/pkg
.for subdir in doc etc gen grp lib tst sysinfo.gap
	${CP} -R ${WRKSRC}/${subdir} ${STAGEDIR}${DATADIR}/
.endfor
.for p in ${MINPACK} ${ADD_PACK}
	(cd ${WRKSRC}/pkg && ${CP} -R $$(ls -d ${p}*) ${STAGEDIR}${DATADIR}/pkg/)
.endfor

.include <bsd.port.mk>
