# Created by: Tomokatsu SAITO <saito@asir.org>
# $FreeBSD$

PORTNAME=	asir
PORTVERSION=	20110810
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.jssac.org/pub/distfiles/asir/ \
		ftp://ftp.asir.org/pub/asir/src/ \
		http://www.hpl.hp.com/personal/Hans_Boehm/gc/gc_source/
DISTFILES=	${ASIR_SRC} ${ASIR_DOC} ${GC_SRC}
EXTRACT_ONLY=	${ASIR_SRC}

MAINTAINER=	saito@asir.org
COMMENT=	The system Risa/Asir is a general computer algebra system

LIB_DEPENDS=	pari-gmp.2:${PORTSDIR}/math/pari

MAKE_JOBS_UNSAFE=	yes
USE_XORG=	x11 xaw xext xt
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf
CONFIGURE_ARGS=	--enable-shared --enable-plot --enable-fep --enable-interval --with-pari --with-gc7
ASIR_SRC_VERSION=	${PORTVERSION}
ASIR_DOC_VERSION=	20110808
GC_VERSION=	7.1
ASIR_SRC=	asir-${ASIR_SRC_VERSION}${EXTRACT_SUFX}
ASIR_DOC=	asirdoc-${ASIR_DOC_VERSION}${EXTRACT_SUFX}
GC_SRC=		gc-${GC_VERSION}${EXTRACT_SUFX}
MAN1=		asir.1
WRKSRC=		${WRKDIR}/asir2000

LIB_DATA=	alpi bfct bgk const cyclic defs.h dfff dmul dmul102 \
		fctrdata fctrtest fff glib gr ifplot katsura launch mat nf \
		num primdec primdec_lex primdec_mod ratint robot solve sp \
		sturm sym weight xm

PORTDOCS=	*
PORTDATA=	*

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-extract:
	@( cd ${WRKSRC}; ${TAR} xfz ${DISTDIR}/${GC_SRC} )
	@${MKDIR} ${WRKDIR}/asirdoc
	@${TAR} xfz ${DISTDIR}/${ASIR_DOC} -C ${WRKDIR}/asirdoc

post-install:
	@${MKDIR} ${DATADIR}
	@(\
	   cd ${WRKSRC}/lib ; \
	   for i in ${LIB_DATA} ; do \
		${INSTALL_DATA} $$i ${DATADIR} ; \
	   done ;\
	   make install-doc \
	)
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_asir
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_plot
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_launch
	@${LN} -fs ${DATADIR} ${PREFIX}/lib/asir
	@${INSTALL_MAN} ${WRKDIR}/asirdoc/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKDIR}/asirdoc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
