# New ports collection makefile for:	amaya
# Version required:	2.2
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

DISTNAME=	amaya-src-2.2
PKGNAME=	amaya-2.2
CATEGORIES= 	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

REQUIRES_MOTIF=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

DIST_SUBDIR=	amaya
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.ifdef ENGLISH_DICT
DISTFILES+=	English.tar.gz
.endif
.ifdef FRENCH_DICT
DISTFILES+=	French.tar.gz
.endif

WRKSRC=		${WRKDIR}/Amaya/obj

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--with-amaya

pre-fetch:
.if !defined(ENGLISH_DICT) && !defined(FRENCH_DICT)
	@${ECHO_MSG} To enable spell checking, define either
	@${ECHO_MSG} ENGLISH_DICT or FRENCH_DICT
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${CP} ${WRKSRC}/Options.orig ${WRKSRC}/Options

post-install:
.for file in amaya print
	strip ${PREFIX}/Amaya/applis/bin/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/../amaya/COPYRIGHT.html ${PREFIX}/Amaya/amaya/
.ifdef ENGLISH_DICT
	${INSTALL_DATA} ${WRKDIR}/dicopar/Eprinc.dic ${PREFIX}/Amaya/dicopar/
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	${ECHO} Amaya/dicopar/Eprinc.dic > ${TMPPLIST}
	${CAT} ${TMPPLIST}.new >> ${TMPPLIST}
	${RM} ${TMPPLIST}.new
.endif
.ifdef FRENCH_DICT
	${INSTALL_DATA} ${WRKDIR}/dicopar/Fprinc.dic ${PREFIX}/Amaya/dicopar/
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	${ECHO} Amaya/dicopar/Fprinc.dic > ${TMPPLIST}
	${CAT} ${TMPPLIST}.new >> ${TMPPLIST}
	${RM} ${TMPPLIST}.new
.endif

.include <bsd.port.mk>
