# New ports collection makefile for:	asir
# Date created:		30 Aug 2001
# Whom:			Tomokatsu SAITO <saito@asir.org>
#
# $FreeBSD$
#

PORTNAME=	asir
PORTVERSION=	20030825
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.jssac.org/pub/distfiles/asir/ \
		ftp://ftp.asir.org/pub/asir/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASIR_DOC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	saito@asir.org
COMMENT=	The system Risa/Asir is a general computer algebra system

LIB_DEPENDS=	pari-2.2:${PORTSDIR}/math/pari-devel

GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
USE_AUTOMAKE_VER=	15
USE_XLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-plot --enable-fep --enable-interval --with-pari=new
ASIR_DOC_VERSION=	20030507
ASIR_DOC=	asirdoc-${ASIR_DOC_VERSION}.tar.gz
MAN1=		asir.1
PREFIX?=	${LOCALBASE}
WRKSRC=		${WRKDIR}/asir2000

LIB_DATA=	alpi bfct bgk const cyclic defs.h dfff dmul fctrdata fctrtest \
		fff gr ifplot katsura launch mat nf num primdec \
		ratint robot solve sp sturm xm

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

pre-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DOCSDIR}

post-install:
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
	@${TAR} xfz ${DISTDIR}/${ASIR_DOC} -C ${DOCSDIR}
	@${INSTALL_MAN} ${DOCSDIR}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>
