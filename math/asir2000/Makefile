# Created by: Tomokatsu SAITO <saito@asir.org>
# $FreeBSD$

PORTNAME=	asir
PORTVERSION=	20140819
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.jssac.org/pub/distfiles/asir/ \
		ftp://ftp.asir.org/pub/asir/src/ \
		http://www.hboehm.info/gc/gc_source/
DISTFILES=	${ASIR_SRC} ${ASIR_DOC} ${GC_SRC}
EXTRACT_ONLY=	${ASIR_SRC}

MAINTAINER=	saito@asir.org
COMMENT=	The system Risa/Asir is a general computer algebra system

LICENSE=	RALUL
LICENSE_NAME=	Risa/Asir Limited Use License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpari.so:${PORTSDIR}/math/pari

MAKE_JOBS_UNSAFE=	yes
USES=		tar:bz2
USE_XORG=	x11 xaw xext xt
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	--enable-shared --enable-plot --enable-fep --enable-interval --with-pari --with-asir-gc --with-gc7
ASIR_SRC_VERSION=	${PORTVERSION}
ASIR_DOC_VERSION=	20140705
GC_VERSION=	7.2e
ASIR_SRC=	asir-${ASIR_SRC_VERSION}${EXTRACT_SUFX}
ASIR_DOC=	asirdoc-${ASIR_DOC_VERSION}${EXTRACT_SUFX}
GC_SRC=		gc-${GC_VERSION}.tar.gz
WRKSRC=		${WRKDIR}/asir2000

LIB_DATA= alpi bfct bgk const cyclic defs.h dfff dmul dmul102 fctrdata \
	fctrtest fff glib gr ifplot katsura launch mat nf num primdec \
	primdec_lex primdec_mod ratint robot solve sp sturm sym weight xm

OPTIONS_DEFINE=	DOCS

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

post-patch:
	${REINPLACE_CMD} '-e s|$${DESTDIR}|${STAGEDIR}|g' \
		${WRKSRC}/lib/Makefile.am

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(\
	   cd ${WRKSRC}/lib ; \
	   for i in ${LIB_DATA} ; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${DATADIR} ; \
	   done ;\
	   make install-doc \
	)
	${LN} -fs ${PREFIX}/bin/asir ${STAGEDIR}${DATADIR}/ox_asir
	${LN} -fs ${PREFIX}/bin/asir ${STAGEDIR}${DATADIR}/ox_plot
	${LN} -fs ${PREFIX}/bin/asir ${STAGEDIR}${DATADIR}/ox_launch
	${LN} -fs ${DATADIR} ${STAGEDIR}${PREFIX}/lib/asir
	${INSTALL_MAN} ${WRKDIR}/asirdoc/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/asirdoc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.post.mk>
