# New ports collection makefile for:	SkyStar3
# Date created:		07 June 2008
# Whom:			Alex Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	ttbudget
PORTVERSION=	5.3
CATEGORIES=	net
MASTER_SITES=	http://paradox.lissyara.su/ \
		http://lissyara.su/patch/skystar3/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	admin@lissyara.su
COMMENT=	Driver for 'TechnoTrend budget DVB S-1401' (SkyStar3)

USE_BZIP2=	yes
SYSDIR?=	${SRC_BASE}/sys
KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
SETENV+=	FROMPORT=1
pre-fetch:
.if !exists(${SYSDIR}/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not compile
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
