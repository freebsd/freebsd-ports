# New ports collection makefile for:	mpqc
# Date created:				27 April 2001
# Whom:					batman <batman@udel.edu>
#
# $FreeBSD$
#

PORTNAME=	mpqc
PORTVERSION=	2.1.3
CATEGORIES=	science parallel
MASTER_SITES=	http://aros.ca.sandia.gov/~cljanss/mpqc/distrib/
DISTFILES=      mpqc-${PORTVERSION}.tar.gz mpqc-val-2.1.0.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+= mpqc-man-${PORTVERSION}.tar.gz mpqc-html-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	maho@FreeBSD.org
COMMENT=	The massively parallel quantum computing library and program

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

USE_BISON=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${FC} \
		--with-libdirs=-L${LOCALBASE}/lib \
		--with-blas="-lf77blas -latlas" \
		--with-lapack="-lalapack -lcblas" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CXXFLAGS}" \
		--with-f77optflags="${FFLAGS}"
USE_PERL5=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty
PLIST_SUB+=	VERSION=${PORTVERSION}
MPQC_COMMAND=	${PREFIX}/bin/mpqc

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=        -O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double
CXXFLAGS+=      -O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -malign-double  -Wno-multichar
.if (${MACHINE_ARCH} == "i386")
CFLAGS+=        -mcpu=i686 -march=i686 -mfancy-math-387
CXXFLAGS+=      -mcpu=i686 -march=i686 -mfancy-math-387
.endif # i386
.endif

pre-configure:
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."

do-install:
	@cd ${WRKSRC} ; ${GMAKE} install
	@cd ${WRKSRC} ; ${GMAKE} install_devel
	@cd ${WRKDIR}/${PORTNAME}-man-${PORTVERSION}/man3/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/man/man3/
	@${MKDIR} ${PREFIX}/share/mpqc/ref
	@cd ${WRKDIR}/ref/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/share/mpqc/ref

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mpqc
	@cd ${WRKDIR}/${PORTNAME}-html-${PORTVERSION} && ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/share/doc/mpqc/
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
