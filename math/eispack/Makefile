# New ports collection makefile for:    eispack
# Version required:     ?
# Date created:         31 October 1994
# Whom:                 ljo
#
# $Id: Makefile,v 1.19 1998/12/01 09:30:25 asami Exp $
#

DISTNAME=	eispack
PKGNAME=	eispack-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/eispack/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/eispack/ \
		ftp://elib.zib-berlin.de/pub/netlib/eispack/

DIST_SUBDIR=	${DISTNAME}

LIB_DEPENDS=	blas.1:${PORTSDIR}/math/blas

EXTRACT_CMD=	${SH} ${SCRIPTDIR}/uncomp
EXTRACT_SUFX=	.gz
EXTRACT_BEFORE_ARGS=	${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes

SRCS =	csroot.f epslon.f pythag.f bakvec.f balanc.f balbak.f bandr.f \
	bandv.f bisect.f bqr.f cbabk2.f cbal.f cg.f ch.f cinvit.f combak.f \
	comhes.f comlr.f comlr2.f comqr.f comqr2.f cortb.f corth.f elmbak.f \
	elmhes.f eltran.f figi.f figi2.f hqr.f hqr2.f htrib3.f htribk.f \
	htrid3.f htridi.f imtql1.f imtql2.f imtqlv.f invit.f minfit.f \
	ortbak.f orthes.f ortran.f otqlrat.f qzhes.f qzit.f qzval.f qzvec.f \
	ratqr.f rebak.f rebakb.f reduc.f reduc2.f rg.f rgg.f rs.f rsb.f \
	rsg.f rsgab.f rsgba.f rsm.f rsp.f rst.f rt.f svd.f tinvit.f tql1.f \
	tql2.f tqlrat.f trbak1.f trbak3.f tred1.f tred2.f tred3.f tridib.f \
	tsturm.f cdiv.f

DISTFILES=	${SRCS:.f=.f.gz}

.include <bsd.port.pre.mk>

pre-build:
	cp Makefile.lib ${WRKDIR}/Makefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libeispack.so.1.0 ${PREFIX}/lib/libeispack.so
.endif

.include <bsd.port.post.mk>
