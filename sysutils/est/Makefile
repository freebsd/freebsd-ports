# New ports collection makefile for:	Enhanced SpeedStep driver
# Date created:				21 August 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	est
PORTVERSION=	0.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/freebsd-est/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Enhanced SpeedStep driver for Pentium M processors

ONLY_FOR_ARCHS=	i386
KMODDIR=	${PREFIX}/modules
MAKE_ARGS=	KMODDIR="${KMODDIR}"

PLIST_FILES=	modules/est.ko			\
		etc/rc.d/est.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500023
EXTRA_PATCHES=	${FILESDIR}/est.c.diff.fbsd4
.endif

post-extract:
	@${SED} -e 's|@@PREFIX@@|${PREFIX}|' ${FILESDIR}/est.sh	\
		> ${WRKDIR}/est.sh

pre-install:
	${MKDIR} ${KMODDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/est.sh ${PREFIX}/etc/rc.d/

.include <bsd.port.post.mk>
