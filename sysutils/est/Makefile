# New ports collection makefile for:	Enhanced SpeedStep driver
# Date created:				21 August 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	est
PORTVERSION=	0.7.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/freebsd-est/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Enhanced SpeedStep driver for Pentium M processors

ONLY_FOR_ARCHS=	i386
KMODDIR=	${PREFIX}/modules
MAKE_ARGS=	KMODDIR="${KMODDIR}"

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

PLIST_FILES=	modules/est.ko			\
		etc/rc.d/est.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600015
IGNORE=		"est now contained in the base system (see cpufreq(4))"
.endif

post-extract:
	${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}	\
		${FILESDIR}/est.sh > ${WRKDIR}/est.sh

pre-install:
	${MKDIR} ${KMODDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/est.sh ${PREFIX}/etc/rc.d/est.sh
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
