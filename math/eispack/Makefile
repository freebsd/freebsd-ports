# New ports collection makefile for:	eispack
# Date created:		31 October 1994
# Whom:			ljo
#
# $FreeBSD$
#

PORTNAME=	eispack
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITES_NETLIB:N*sandia*}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${SRCS}
EXTRACT_ONLY=	#empty

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Eigenvalue system package

MASTER_SITES_NETLIB=	ftp://ftp.netlib.org/%SUBDIR%/ \
		http://www.netlib.org/%SUBDIR%/ \
		http://www.netlib.no/netlib/%SUBDIR%/ \
		http://netlib.sandia.gov/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/netlib.bell-labs.com/netlib/%SUBDIR%/ \
		http://artfiles.org/netlib.org/%SUBDIR%/ \
		http://netlib.amss.ac.cn/%SUBDIR%/ \
		http://netlib.caspur.it/%SUBDIR%/ \
		http://netlib.ccp14.ac.uk/%SUBDIR%/ \
		http://netlib.enseeiht.fr/%SUBDIR%/ \
		http://netlib.linux-mirror.org/%SUBDIR%/ \
		http://phase.hpcc.jp/mirrors/netlib/%SUBDIR%/

DIST_SUBDIR=	${PORTNAME}
NO_WRKSUBDIR=	yes

USE_FORTRAN=	yes
USE_LDCONFIG=	yes

SHLIB_MAJOR=	2
PLIST_FILES=	lib/libeispack.a lib/libeispack.so lib/libeispack.so.${SHLIB_MAJOR}

LDFLAGS+=	${FFLAGS}
SRCCONF=	${NONEXISTENT}
MAKE_ENV+=	LDFLAGS="${LDFLAGS}" SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF="${SRCCONF}"

OPTIONS=	PROFILE "Build and install a profiling library" Off

.include <bsd.port.options.mk>

.if defined(WITH_PROFILE)
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE  =	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libeispack_p.a
.else
MAKE_ENV+=	NO_PROFILE=
.endif

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

post-extract:
	@(cd ${_DISTDIR}; ${CP} ${SRCS} ${WRKSRC})
	${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

.include <bsd.port.mk>
