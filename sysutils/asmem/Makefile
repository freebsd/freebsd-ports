# New ports collection makefile for:	asfsm
# Date created:		4 June 1999
# Whom:				jack
#
# $FreeBSD$
#

PORTNAME=		asmem
PORTVERSION=		1.6
CATEGORIES=		sysutils afterstep
MASTER_SITES=		${MASTER_SITE_AFTERSTEP} \
			http://www.bewoner.dma.be/Albert/software/
MASTER_SITE_SUBDIR=	apps/asmem

MAINTAINER=	jack@germanium.xtalwind.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
MAKEFILE=	Makefile.UNIX
MAN1=		asmem.1
MAKE_ENV+=	PCFLAGS="${CFLAGS}"

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 400000
BROKEN=		"missing sys/rlist.h on 4.0 and later"
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/asmem.man ${PREFIX}/man/man1/asmem.1
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} \
		-g kmem -m 2755 ${WRKSRC}/asmem ${PREFIX}/bin

.include <bsd.port.post.mk>
