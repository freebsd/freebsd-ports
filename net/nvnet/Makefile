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

NVVERSION=	0261
NVNETVERSION=	20031108

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/nvnet
MAN4=		nvnet.4

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 480100 || ${OSVERSION} >= 500000 && ${OSVERSION} < 501000
BROKEN=		"Systems prior to FreeBSD 4.9 & 5.1 are not supported"
.endif

.if ${OSVERSION} < 500000
PLIST_SUB+=	FREEBSD5="@comment " FREEBSD4=""
.else
PLIST_SUB+=	FREEBSD5="" FREEBSD4="@comment "
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
	@${ECHO} "*************************************************"; \
	${ECHO}  "This port requires the kernel source be available"; \
	${ECHO}  "*************************************************"; \
	exit 1
.endif

port-install:
.if !defined(NOPORTSDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALLMAN} ${WRKSRC}/doc/README ${WRKSRC}/doc/nvidia_pci.c.diff \
	    ${DOCSDIR}
.endif
	${INSTALLMAN} ${WRKSRC}/man/nvnet.4 ${PREFIX}/man/man4
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
