# New ports collection makefile for:	asir
# Date created:		30 Aug 2001
# Whom:			Tomokatsu SAITO <saito@asir.org>
#
# $FreeBSD$
#

PORTNAME=	asir
PORTVERSION=	20021020
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.jssac.org/pub/distfiles/asir/ \
		ftp://ftp.asir.org/pub/asir/src/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASIR_DOC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	saito@asir.org

WRKSRC=		${WRKDIR}/asir2000
PREFIX?=	${LOCALBASE}
USE_IMAKE=	YES
XFREE86_HTML_MAN=NO
USE_X_PREFIX=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ENV=	OLD_PARI_VERSION=${OLD_PARI_VERSION} \
		PARI_VERSION=${PARI_VERSION} \
		LAPACK_VERSION=${LAPACK_VERSION}
CONFIGURE_ARGS= -oxhome ${PREFIX} -plot ${PARI} -fep -interval ${LAPACK}
ASIR_DOC_VERSION=	20021020
ASIR_DOC=	asirdoc-${ASIR_DOC_VERSION}.tar.gz
MAN1=		asir.1

LIB_DATA=	alpi bfct bgk const cyclic defs.h dfff dmul fctrdata fctrtest \
		fff gr ifplot katsura launch mat nf num primdec \
		ratint robot solve sp sturm xm
LIB_DEPENDS=	# dummy

OLD_PARI_DIR=	${PORTSDIR}/math/pari
OLD_PARI_VERSION=	`${GREP} PORTVERSION ${OLD_PARI_DIR}/Makefile | cut -f 2`
PARI_DIR=	${PORTSDIR}/math/pari-devel
PARI_VERSION=	`${GREP} MAJOR_VERSION ${PARI_DIR}/Makefile | ${GREP} -v { | cut -f 2`.`${GREP} MINOR_VERSION ${PARI_DIR}/Makefile | ${GREP} -v { | cut -f 2`.`${GREP} REV_VERSION ${PARI_DIR}/Makefile | ${GREP} -v { | cut -f 2`.alpha

.if defined(USE_OLDPARI)
LIB_DEPENDS+=	pari.1:${OLD_PARI_DIR}
PARI=	-oldpari
.else
LIB_DEPENDS+=	pari-2.2:${PARI_DIR}
PARI=	-pari
.endif

LAPACK_DIR=	${PORTSDIR}/math/lapack
LAPACK_VERSION=	`${GREP} PORTVERSION ${LAPACK_DIR}/Makefile | cut -f 2`

.if defined(USE_LAPACK)
LIB_DEPENDS+=	lapack.3:${LAPACK_DIR}
LAPACK=	-lapack
.else
LAPACK=
.endif

pre-extract:
.if !defined(USE_OLDPARI)
	@${ECHO_MSG} "If you build the pari ${OLD_PARI_VERSION} library,"
	@${ECHO_MSG} "    make USE_OLDPARI=yes"
	@${ECHO_MSG} "otherwise link pari ${PARI_VERSION}"
.endif
.if !defined(USE_LAPACK)
	@${ECHO_MSG} "To build include \"LAPACK\" library,"
	@${ECHO_MSG} "    make USE_LAPACK=yes"
.endif

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
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_asir
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_plot
	@${LN} -fs ${PREFIX}/bin/asir ${DATADIR}/ox_launch
	@${TAR} xfz ${DISTDIR}/${ASIR_DOC} -C ${DOCSDIR}
	@${INSTALL_MAN} ${DOCSDIR}/${MAN1} ${PREFIX}/man/man1
	@${GZIP_CMD} ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
