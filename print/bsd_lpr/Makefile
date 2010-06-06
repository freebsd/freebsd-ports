# New ports collection makefile for:	bsd_lpr
# Date created:		7th February 2010
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bsd_lpr
PORTVERSION=	2010020702
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	bms
DISTNAME=	bsd_lpr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD lpr suite

CONFLICTS=	cups-base-[0-9]* LPRng-[0-9]*

USE_BZIP2=	yes
MAKE_JOBS_SAFE=	defined

OPTIONS=	\
	INET6	 "Build with IPv6 support" On

USE_RC_SUBR=	bsd_lpd
SUB_FILES+=	pkg-message

#
# To roll snapshot: as bms: make BOOTSTRAP=defined fetch
#
.if defined(BOOTSTRAP)
FETCH_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
SVN_REV=	202921		# svn tip at epoch 2010020702
SVNROOT_URI=	svn://svn.freebsd.org/base
SVN_BRANCH=	stable/8
SVN_SUBDIR=	usr.sbin/lpr

do-fetch:
	${MKDIR} ${WRKDIR}
	svn export -r ${SVN_REV} ${SVNROOT_URI}/${SVN_BRANCH}/${SVN_SUBDIR} ${WRKSRC}
	cd ${WRKDIR}; tar cvfy ${DISTDIR}/${DISTNAME}.tar.bz2 ${DISTNAME}
.if ${USER} == bms
	${CHMOD} ugo+r ${DISTDIR}/${DISTNAME}.tar.bz2
	scp -p ${DISTDIR}/${DISTNAME}.tar.bz2 \
	    freefall.freebsd.org:public_distfiles/
.endif
.endif # defined(BOOTSTRAP)

PLIST_FILES=\
	sbin/chkprintcap \
	sbin/lp \
	sbin/lpc \
	sbin/lpd \
	sbin/lpq \
	sbin/lpr \
	sbin/lprm \
	sbin/lptest \
	sbin/pac \
	sbin/lpf \
	sbin/bjc-240.sh.sample \
	sbin/koi2855 \
	sbin/koi2alt

LPR_SUBST_FILES=	${WRKSRC}/common_source/pathnames.h

.if defined(WITHOUT_INET6)
MAKE_ARGS+=	WITHOUT_INET6_SUPPORT=defined
.endif

MAKE_ARGS+=\
	BINDIR="${PREFIX}/sbin" \
	SHAREDIR="${PREFIX}/share" \
	MANDIR="${MANPREFIX}/man/man"

.if !defined(NOPORTDOCS) && !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED=	yes
MAN1=	lp.1 lpq.1 lpr.1 lprm.1 lptest.1
MAN5=	printcap.5
MAN8=	chkprintcap.8 lpc.8 lpd.8 pac.8

LPR_SUBST_FILES+=\
	${WRKSRC}/lp/lp.1 \
	${WRKSRC}/lpq/lpq.1 \
	${WRKSRC}/lpr/lpr.1 \
	${WRKSRC}/lprm/lprm.1 \
	${WRKSRC}/lptest/lptest.1 \
	${WRKSRC}/lpr/printcap.5 \
	${WRKSRC}/chkprintcap/chkprintcap.8 \
	${WRKSRC}/lpc/lpc.8 \
	${WRKSRC}/lpd/lpd.8 \
	${WRKSRC}/pac/pac.8
.else
NOMAN=		defined
MAKE_ARGS+=	WITHOUT_MAN=defined
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
IGNORE=		unsupported on FreeBSD versions prior to 8.0-RELEASE
.endif

# XXX clobbering ETCDIR
ETCDIR=	${PREFIX}/etc

post-patch:
	@${TOUCH} ${WRKDIR}/Makefile.inc
	@${REINPLACE_CMD} -e \
	    's!/etc/printcap!${ETCDIR}/printcap!g ; \
	     s!/usr/sbin!${PREFIX}/sbin!g' \
	    ${LPR_SUBST_FILES}

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS) && !defined(NO_INSTALL_MANPAGES)
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} maninstall)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
