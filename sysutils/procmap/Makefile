# New ports collection makefile for:	procmap
# Version required:	(self contained)
# Date created:		22 March 2000
# Whom:			Jason Evans <jasone@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	procmap-1.0
CATEGORIES=	sysutils
DISTFILES=	#empty

MAINTAINER=	jasone@freebsd.org

NO_CHECKSUM=	yes
NO_WRKSUBDIR=	yes

WRKSRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

pre-clean:
	@$(SH) -ec "cd $(WRKSRC) ; make clean"

.include <bsd.port.mk>
