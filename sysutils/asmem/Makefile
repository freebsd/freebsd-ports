# New ports collection makefile for:	asfsm
# Version required:	asmem-1.2
# Date created:		4 June 1999
# Whom:				jack
#
# $Id: Makefile,v 1.1.1.1 1999/06/14 19:26:35 taoka Exp $

DISTNAME=	asmem-1.2
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://www.bewoner.dma.be/Albert/software/

MAINTAINER=	jack@germnaium.xtalwind.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes

MAKEFILE=	Makefile.UNIX

MAN1=		asmem.1

do-install:
		${INSTALL_MAN} ${WRKSRC}/asmem.man ${PREFIX}/man/man1/asmem.1
		${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} \
			-g kmem -m 2755 ${WRKSRC}/asmem ${PREFIX}/bin

.include <bsd.port.mk>
