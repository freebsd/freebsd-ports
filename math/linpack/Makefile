# New ports collection makefile for:    linpack
# Version required:     ?
# Date created:         31 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.18 1998/12/01 09:55:09 asami Exp $
#

DISTNAME=	linpack
PKGNAME=	linpack-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/linpack/ \
		ftp://www.hensa.ac.uk/mirrors/linpack/ \
		ftp://elib.zib-berlin.de/pub/linpack/

DIST_SUBDIR=	${DISTNAME}

LIB_DEPENDS=    blas.1:${PORTSDIR}/math/blas

EXTRACT_CMD=	${SH} ${SCRIPTDIR}/uncomp
EXTRACT_SUFX=	.gz
EXTRACT_BEFORE_ARGS=	${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes

SRCS =	cchdc.f cchdd.f cchex.f cchud.f cgbco.f cgbdi.f cgbfa.f cgbsl.f \
	cgeco.f cgedi.f cgefa.f cgesl.f cgtsl.f chico.f chidi.f chifa.f \
	chisl.f chpco.f chpdi.f chpfa.f chpsl.f cmach.f cpbco.f cpbdi.f \
	cpbfa.f cpbsl.f cpoco.f cpodi.f cpofa.f cposl.f cppco.f cppdi.f \
	cppfa.f cppsl.f cptsl.f cqrdc.f cqrsl.f csico.f csidi.f csifa.f \
	csisl.f cspco.f cspdi.f cspfa.f cspsl.f csvdc.f ctrco.f ctrdi.f \
	ctrsl.f dchdc.f dchdd.f dchex.f dchud.f dgbco.f dgbdi.f dgbfa.f \
	dgbsl.f dgeco.f dgedi.f dgefa.f dgesl.f dgtsl.f dmach.f dpbco.f \
	dpbdi.f dpbfa.f dpbsl.f dpoco.f dpodi.f dpofa.f dposl.f dppco.f \
	dppdi.f dppfa.f dppsl.f dptsl.f dqrdc.f dqrsl.f dsico.f dsidi.f \
	dsifa.f dsisl.f dspco.f dspdi.f dspfa.f dspsl.f dsvdc.f dtrco.f \
	dtrdi.f dtrsl.f schdc.f schdd.f schex.f schud.f sgbco.f sgbdi.f \
	sgbfa.f sgbsl.f sgeco.f sgedi.f sgefa.f sgesl.f sgtsl.f smach.f \
	spbco.f spbdi.f spbfa.f spbsl.f spoco.f spodi.f spofa.f sposl.f \
	sppco.f sppdi.f sppfa.f sppsl.f sptsl.f sqrdc.f sqrsl.f ssico.f \
	ssidi.f ssifa.f ssisl.f sspco.f sspdi.f sspfa.f sspsl.f ssvdc.f \
	strco.f strdi.f strsl.f zchdc.f zchdd.f zchex.f zchud.f zgbco.f \
	zgbdi.f zgbfa.f zgbsl.f zgeco.f zgedi.f zgefa.f zgesl.f zgtsl.f \
	zhico.f zhidi.f zhifa.f zhisl.f zhpco.f zhpdi.f zhpfa.f zhpsl.f \
	zmach.f zpbco.f zpbdi.f zpbfa.f zpbsl.f zpoco.f zpodi.f zpofa.f \
	zposl.f zppco.f zppdi.f zppfa.f zppsl.f zptsl.f zqrdc.f zqrsl.f \
	zsico.f zsidi.f zsifa.f zsisl.f zspco.f zspdi.f zspfa.f zspsl.f \
	zsvdc.f ztrco.f ztrdi.f ztrsl.f

DISTFILES=	${SRCS:.f=.f.gz}

.include <bsd.port.pre.mk>

pre-build:
	cp Makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf liblinpack.so.1.0 ${PREFIX}/lib/liblinpack.so
.endif

.include <bsd.port.post.mk>
