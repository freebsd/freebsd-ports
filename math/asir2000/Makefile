# New ports collection makefile for:	asir
# Date created:		30 Aug 2001
# Whom:			Tomokatsu SAITO <saito@asir.org>
#
# $FreeBSD$
#

PORTNAME=	asir
PORTVERSION=	20020108
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.asir.org/pub/asir/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASIR_DOC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	saito@asir.org

.if defined(USE_LAPACK)
LIB_DEPENDS=	lapack.3:${PORTSDIR}/math/lapack
.endif
.if defined(USE_OLDPARI)
LIB_DEPENDS+=	pari.1:${PORTSDIR}/math/pari
.else
LIB_DEPENDS+=	pari-2.2.0:${PORTSDIR}/math/pari-devel
.endif

.if defined(USE_LAPACK)
LAPACK=	-lapack
.else
LAPACK=
.endif
.if defined(USE_OLDPARI)
PARI=	-oldpari
.else
PARI=	-pari
.endif
WRKSRC=		${WRKDIR}/asir2000
PREFIX?=	${LOCALBASE}
USE_IMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= -oxhome ${PREFIX} -plot ${PARI} -fep -interval ${LAPACK}
ASIR_DOC=	asirdoc-${PORTVERSION}.tar.gz

LIB_DATA=	alpi bfct bgk const cyclic defs.h dfff dmul fctrdata fctrtest \
		fff gr ifplot katsura launch mat nf num primdec \
		ratint robot solve sp sturm xm

pre-everything::
	@${ECHO_MSG} ""
.if !defined(USE_OLDPARI)
	@${ECHO_MSG} "If you build with the older pari 2.1.1 library,"
	@${ECHO_MSG} "    make USE_OLDPARI=yes"
	@${ECHO_MSG} "otherwise it will link the newer pari 2.2.0 library."
.endif
	@${ECHO_MSG} ""
.if !defined(USE_LAPACK)
	@${ECHO_MSG} "To build with the \"LAPACK\" library,"
	@${ECHO_MSG} "    make USE_LAPACK=yes"
.endif
	@${ECHO_MSG} ""

pre-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DOCSDIR}

post-install:
	@(\
	   cd ${WRKSRC}/lib ; \
	   for i in ${LIB_DATA} ; do \
		${INSTALL_DATA} $$i ${DATADIR} ; \
	   done \
	)
	@(cd ${WRKSRC}; make install-doc)
	@${LN} -s ${PREFIX}/bin/asir ${DATADIR}/ox_asir
	@${LN} -s ${PREFIX}/bin/asir ${DATADIR}/ox_plot
	@${LN} -s ${PREFIX}/bin/asir ${DATADIR}/ox_launch
	@${TAR} xfz ${DISTDIR}/${ASIR_DOC} -C ${DOCSDIR}

.include <bsd.port.mk>
