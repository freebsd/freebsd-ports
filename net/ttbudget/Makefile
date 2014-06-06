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

BROKEN=		does not build, mastersite disapperead, not staged
DEPRECATED=		${BROKEN}
EXPIRATION_DATE=        2014-07-06

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

.include <bsd.port.post.mk>
