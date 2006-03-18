# New ports collection makefile for:	Enhanced SpeedStep driver
# Date created:				21 August 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	est
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daemonology.net/freebsd-est/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Enhanced SpeedStep driver for Pentium M processors

ONLY_FOR_ARCHS=	i386
KMODDIR=	${PREFIX}/modules
MAKE_ARGS=	KMODDIR="${KMODDIR}"

USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600015
IGNORE=		is now contained in the base system (see cpufreq(4))
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		needs kernel source files
.endif

pre-install:
	@${MKDIR} ${KMODDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
