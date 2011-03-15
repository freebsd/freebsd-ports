# New ports collection makefile for:	eispack
# Date created:		31 October 1994
# Whom:			ljo
#
# $FreeBSD$
#

PORTNAME=	eispack
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/eispack/ \
		ftp://ftp.mirrorservice.org/sites/netlib.bell-labs.com/netlib/eispack/
DISTFILES=	${SRCS:.f=.f.gz}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eigenvalue system package

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

DIST_SUBDIR=	${PORTNAME}
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes

USE_FORTRAN=	yes

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

do-extract:
	@${MKDIR} ${WRKDIR}
.for file in ${SRCS}
	@${GZCAT} ${_DISTDIR}/${file:.f=.f.gz} > ${WRKSRC}/${file}
.endfor

pre-build:
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

.include <bsd.port.mk>
