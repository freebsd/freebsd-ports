# New ports collection makefile for:	amaya
# Date created:		26 Dec 1998
# Whom:			Don Croyle <croyle@gelemna.ft-wayne.in.us>
#
# $FreeBSD$
#

PORTNAME=	amaya
PORTVERSION= 	2.4
CATEGORIES= 	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	croyle@gelemna.ft-wayne.in.us

REQUIRES_MOTIF=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
DIST_SUBDIR=	amaya
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

DICT?=		none

.if ${DICT} != "none"
.if ${DICT} == "all"
DISTFILES+=    Dutch.tgz
DISTFILES+=    English.tgz
DISTFILES+=    French.tgz
DISTFILES+=    German.tgz
DISTFILES+=    Italian.tgz
DISTFILES+=    Spanish.tgz
DISTFILES+=    Swedish.tgz
.else
DISTFILES+=    ${DICT:S/$/.tgz/g}
.endif
.endif

WRKSRC=		${WRKDIR}/Amaya/obj

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--with-amaya

pre-fetch:
.if ${DICT} == "none"
	@${ECHO_MSG} Several spellchecking dictionaries are available.  To use
	@${ECHO_MSG} one of them, define DICT to be the appropriate language.
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${CP} ${WRKSRC}/Options.orig ${WRKSRC}/Options

post-install:
.for file in amaya print
	strip ${PREFIX}/Amaya/applis/bin/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/../amaya/COPYRIGHT.html\
	${PREFIX}/Amaya/amaya/
.if ${DICT} != "none"
	${INSTALL_DATA} ${WRKDIR}/*.dic ${PREFIX}/Amaya/dicopar/
	${MV} ${TMPPLIST} ${TMPPLIST}.new
	cd ${WRKDIR} && ls -1 *.dic | perl -pi -e 's|^|Amaya/dicopar/|'\
	> ${TMPPLIST}
	${CAT} ${TMPPLIST}.new >> ${TMPPLIST}
	${RM} ${TMPPLIST}.new
.endif

.include <bsd.port.mk>
