# ex:ts=8
# Ports collection makefile for:  jive
# Version required:     	  1.1
# Date created:			  Mon Feb 17, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	jive-1.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.nuxi.com/pub/misc/

MAINTAINER=     obrien@FreeBSD.org

WRKSRC=		${WRKDIR}/jive
MAN1=		jive.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jive ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
