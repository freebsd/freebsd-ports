# New ports collection makefile for:	asfsm
# Version required:	asmem-1.2
# Date created:		4 June 1999
# Whom:				jack
#
# $FreeBSD$

DISTNAME=	asmem-1.4
CATEGORIES=	sysutils afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/apps/asmem/ \
		http://www.bewoner.dma.be/Albert/software/

MAINTAINER=	jack@germanium.xtalwind.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400000
BROKEN=		"Sorry, asmem doesn't compile on 4.0+"
.endif

USE_X_PREFIX=	yes

MAKEFILE=	Makefile.UNIX

MAN1=		asmem.1

do-install:
		${INSTALL_MAN} ${WRKSRC}/asmem.man ${PREFIX}/man/man1/asmem.1
		${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} \
			-g kmem -m 2755 ${WRKSRC}/asmem ${PREFIX}/bin

.include <bsd.port.post.mk>
