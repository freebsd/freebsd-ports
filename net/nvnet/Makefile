# Ports collection makefile for: nvnet
#
# Date created:	1 Oct 2003
# Whom: 	Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	nvnet
PORTVERSION=	1.0.${NVVERSION}
PORTREVISION?=	0
CATEGORIES=	net
MASTER_SITES=	http://download.nvidia.com/XFree86/nforce/1.0-${NVVERSION}/:nvidia \
		ftp://download.nvidia.com/XFree86/nforce/1.0-${NVVERSION}/:nvidia \
		http://download1.nvidia.com/XFree86/nforce/1.0-${NVVERSION}/:nvidia \
		ftp://download1.nvidia.com/XFree86/nforce/1.0-${NVVERSION}/:nvidia \
		http://www.onthenet.com.au/~q/nvnet/:nvnet
DISTFILES=	NVIDIA_nforce-1.0-${NVVERSION}${EXTRACT_SUFX}:nvidia \
		nvnet-src-${NVNETVERSION}${EXTRACT_SUFX}:nvnet

MAINTAINER=	q@onthenet.com.au
COMMENT=	Driver for NVIDIA MCP Ethernet adapter

NVNETVERSION=	20040813

NO_PACKAGE=	Depends on kernel
ONLY_FOR_ARCHS=	amd64 i386
MD5_FILE=	${MASTERDIR}/distinfo.${ARCH}
WRKSRC=		${WRKDIR}/nvnet
MODULES_WITH_WORLD=
PLIST_SUB=	KMODDIR=${KMODDIR}
PORTDOCS=	README nvidia_pci.c.diff
MAN4=		nvnet.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 480100 || ${OSVERSION} >= 500000 && ${OSVERSION} < 501000
BROKEN=		"Systems prior to FreeBSD 4.9 & 5.1 are not supported"
.endif

.if ${ARCH} == "i386"
NVVERSION=	0274
.elif ${ARCH} == "amd64"
NVVERSION=	0275
.else
NVVERSION=	0
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/module/if_nv.ko ${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/man/nvnet.4 ${PREFIX}/man/man4
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
