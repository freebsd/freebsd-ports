DISTNAME=	eispack
DISTDIR=${PORTSDIR}/distfiles/${DISTNAME}
MASTER_SITES=	ftp://netlib.att.com/netlib/eispack/
.if defined(MASTER_SITE_OVERRIDE)
MASTER_SITES:= ${MASTER_SITE_OVERRIDE}/eispack/
.undef MASTER_SITE_OVERRIDE
.endif
EXTRACT_CMD=${.CURDIR}/scripts/uncomp
EXTRACT_SUFX=.Z
EXTRACT_ARGS= ${WRKDIR}
WRKSRC=${WRKDIR}

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

DISTFILES=	${SRCS:.f=.f.Z}

pre-build:
	cp Makefile.lib ${WRKDIR}/Makefile

pre-extract:
	chmod +x scripts/uncomp

.include <bsd.port.mk>

