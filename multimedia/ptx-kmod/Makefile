# New ports collection makefile for:	ptx-kmod
# Date created:		July 2 2011
# Whom:			hrs
#
# $FreeBSD$
#

PORTNAME=	ptx
PORTVERSION=	0.0.20111212
CATEGORIES=	multimedia kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	hrs
PKGNAMESUFFIX=	-kmod
DISTNAME=	${PORTNAME}-${PORTVERSION:S,0.0.,,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Device driver for PT1/PT2 ISDB-S/T tuner cards

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64 i386
BUILD_WRKSRC=	${WRKSRC}/dev/ptx
MAKE_ENV=	KMODDIR=${PREFIX}/${KMODDIR} SYSDIR=${SYSDIR}
PLIST_FILES=	${KMODDIR}/ptx.ko bin/recptx.pl
PLIST_DIRS=	${KMODDIR}
SUB_LIST=	KMODDIR=${KMODDIR}
USE_RC_SUBR=	ptx
PORTDOCS=	README

.include <bsd.port.pre.mk>

KMODDIR=	libexec/${PORTNAME}
SYSDIR?=	${SRC_BASE}/sys

KERNCONF?=	GENERIC

# Use the first component of ${KERNCONF}.
.for K in ${KERNCONF}
_KERNCONF?=$K
.endfor

.if !exists(${SRC_BASE}/sys/${ARCH}/conf/${_KERNCONF})
IGNORE=		requires kernel source to be installed
.endif

do-install:
	@${MKDIR} ${PREFIX}/${KMODDIR}
	${INSTALL_KLD} ${BUILD_WRKSRC}/ptx.ko ${PREFIX}/${KMODDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/recptx.pl ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
