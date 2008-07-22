# New ports collection makefile for:	SkyStar3
# Date created:		07 June 2008
# Whom:			Alex Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	ttbudget
PORTVERSION=	4
CATEGORIES=	net
MASTER_SITES=	http://paradox.org.ua/ \
		http://lissyara.su/patch/skystar3/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	Driver for 'TechnoTrend budget DVB S-1401' (SkyStar3)

USE_BZIP2=	yes
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}
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

.include <bsd.port.mk>
