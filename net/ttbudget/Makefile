# Created by: Alex Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	ttbudget
PORTVERSION=	5.3
PORTREVISION=	1
CATEGORIES=	net kld
MASTER_SITES=	http://paradox.lissyara.su/ \
		http://lissyara.su/patch/skystar3/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}

MAINTAINER=	admin@lissyara.su
COMMENT=	Driver for 'TechnoTrend budget DVB S-1401' (SkyStar3)

USE_BZIP2=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerprc, or sparc64
.else
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
