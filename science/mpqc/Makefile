# New ports collection makefile for:	mpqc
# Date created:				27 April 2001
# Whom:					batman <batman@udel.edu>
#
# $FreeBSD$
#

PORTNAME=	mpqc
PORTVERSION=	2.2.3
CATEGORIES=	science parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mpqc
DISTFILES=	mpqc-${PORTVERSION}.tar.bz2 mpqc-val-${PORTVERSION}.tar.bz2
.if !defined(NOPORTDOCS)
DISTFILES+=	mpqc-man-${PORTVERSION}.tar.bz2 mpqc-html-${PORTVERSION}.tar.bz2
.endif

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The massively parallel quantum computing library and program

.if defined(WITH_ICC)
BUILD_DEPENDS+=  ${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas

GNU_CONFIGURE=	yes
USE_AUTOCONF_VER=259

.if defined(WITH_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -xMKW -Vaxlib
CXXFLAGS=	-O3 -tpp7 -xMKW -Vaxlib
.endif
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack -lcblas

CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${FC} \
		--with-libdirs=-L${LOCALBASE}/lib \
		--with-blas="${BLAS}" \
		--with-lapack="${LAPACK}" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CXXFLAGS}" \
		--with-f77optflags="${FFLAGS}" \
		--with-include="-I${WRKDIR}"
.if defined(WITH_ICC)
CONFIGURE_ARGS+=--with-libs="-lsvml"
.endif

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
ALL_TARGET=	# empty
PLIST_SUB+=	VERSION=${PORTVERSION}
MPQC_COMMAND=	${PREFIX}/bin/mpqc

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O2 -ffast-math
CXXFLAGS+=	-O2 -ffast-math
.endif

pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
	#${CP} ${FILESDIR}/FlexLexer.h ${WRKDIR}
do-install:
	@cd ${WRKSRC} ; ${GMAKE} install
	@cd ${WRKSRC} ; ${GMAKE} install_devel
	@cd ${WRKDIR}/${PORTNAME}-man-${PORTVERSION}/man3/ ; \
	${INSTALL_MAN} * ${PREFIX}/man/man3
	@${MKDIR} ${PREFIX}/share/mpqc/ref
	@cd ${WRKDIR}/ref/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/share/mpqc/ref
	@${FIND} ${PREFIX}/share/mpqc/ref | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${PREFIX}/share/mpqc/ref -type f | ${XARGS} ${CHMOD} ${SHAREMODE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-html-${PORTVERSION} && ${TAR} -chf - . | \
		${TAR} -xf - -C ${DOCSDIR}
	@${FIND} ${DOCSDIR} | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
.endif

validate:   # it takes few days
	@cd ${WRKSRC}/src/bin/mpqc/validate ; ${RM} -f ref ; ${LN} -s ${WRKSRC}/../ref .
	@cd ${WRKSRC}/src/bin/mpqc/validate ; ${GMAKE} inputs
	@cd ${WRKSRC}/src/bin/mpqc/validate ; \
	for i in run/*.in ; \
	do \
	${ECHO} "Now calculating `basename $$i`"; \
	${MPQC_COMMAND} $$i > $${i%.in}.out ; \
	done
	@cd ${WRKSRC}/src/bin/mpqc/validate ; ${GMAKE} check

.include <bsd.port.post.mk>
