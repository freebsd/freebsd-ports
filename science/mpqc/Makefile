# New ports collection makefile for:	mpqc
# Date created:				27 April 2001
# Whom:					batman <batman@udel.edu>
#
# $FreeBSD$
#

PORTNAME=	mpqc
PORTVERSION=	2.1.2
CATEGORIES=	science
MASTER_SITES=	http://aros.ca.sandia.gov/~cljanss/mpqc/distrib/
DISTFILES=      mpqc-${PORTVERSION}.tar.gz mpqc-val-2.1.0.tar.gz
.if !defined(NOPORTDOCS)
DISTFILES+= mpqc-man-${PORTVERSION}.tar.gz mpqc-html-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	maho@FreeBSD.org

LIB_DEPENDS=	lapack:${PORTSDIR}/math/lapack \
		atlas:${PORTSDIR}/math/atlas

.include <bsd.port.pre.mk>

USE_BISON=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--with-cc=${CC} \
		--with-cxx=${CXX} \
		--with-f77=${F77} \
		--with-libdirs=-L${LOCALBASE}/lib \
		--with-blas="-lf77blas -latlas" \
		--with-lapack="-lalapack -lcblas" \
		--with-coptflags="${CFLAGS}" \
		--with-cxxoptflags="${CXXFLAGS}" \
		--with-f77optflags="${FFLAGS}"
USE_PERL5=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty
MPQC_COMMAND=	${PREFIX}/bin/mpqc

.include "${.CURDIR}/files/manpages"

pre-configure:
	@${ECHO} "You can override and CFLAGS on the command line."
	@${ECHO} "Following is a recommended one."
	@${ECHO} "make CFLAGS=\"-malign-double -fexpensive-optimizations -O4 -ffast-math -funroll-loops\""

do-install:
	@cd ${WRKSRC} ; ${GMAKE} install
	@cd ${WRKSRC} ; ${GMAKE} install_devel
	@cd ${WRKDIR}/${PORTNAME}-man-${PORTVERSION}/man3/ ; ${TAR} -chf - . | \
		${TAR} -xf - -C ${PREFIX}/man/man3/
	@${MKDIR} ${PREFIX}/share/mpqc/ref
	@cd ${WRKDIR}/ref/ && ${TAR} -chf - . | \
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
