# New ports collection makefile for:	asir
# Date created:		30 Aug 2001
# Whom:			Tomokatsu SAITO <saito@asir.org>
#
# $FreeBSD$
#

PORTNAME=	asir
PORTVERSION=	20010830
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.asir.org/pub/asir/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASIR_DOC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	saito@asir.org

LIB_DEPENDS=	pari.1:${PORTSDIR}/math/pari \
		lapack.3:${PORTSDIR}/math/lapack

WRKSRC=		${WRKDIR}/asir2000
PREFIX?=	${LOCALBASE}
USE_IMAKE=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS= -oxhome ${PREFIX} -plot -pari -fep -interval -lapack

ASIR_DOC=	asirdoc-${PORTVERSION}.tar.gz
LIB_DATA=	alpi bfct bgk const cyclic defs.h dfff dmul fctrdata fctrtest \
		fff gr ifplot katsura launch mat nf num primdec \
		ratint robot solve sp sturm xm

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
