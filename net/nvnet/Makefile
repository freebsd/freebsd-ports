# Ports collection makefile for: nvnet
# Date created:	1 Oct 2003
# Whom: 	Quinton Dolan <q@onthenet.com.au>
#
# $FreeBSD$
#

PORTNAME=	nvnet
PORTVERSION=	1.0.0301
CATEGORIES=	net
MASTER_SITES=	http://www.onthenet.com.au/~q/nvnet/
DISTFILES=	${PORTNAME}-src-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	q@onthenet.com.au
COMMENT=	Driver for NVIDIA MCP Ethernet adapter

DISTVERSION=	20050312

NO_PACKAGE=	Depends on kernel
ONLY_FOR_ARCHS=	amd64 i386
WRKSRC=		${WRKDIR}/nvnet
PLIST_SUB=	KMODDIR=${KMODDIR}
PORTDOCS=	README nvidia_pci.c.diff
MAN4=		nvnet.4
MAKE_ENV=	OSTYPE=${OPSYS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 480100 || ${OSVERSION} >= 500000 && ${OSVERSION} < 501000
IGNORE=		Systems prior to FreeBSD 4.9 & 5.1 are not supported
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		Kernel source files required
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
