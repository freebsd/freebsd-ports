# ex:ts=8
# Ports collection makefile for:  detex
# Version required:     	  2.6
# Date created:			  Mon Feb 17, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.1.1.1 1997/03/25 10:53:08 obrien Exp $
#

DISTNAME=	detex-2.6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.purdue.edu/pub/trinkle/
EXTRACT_SUFX=	.tar

MAINTAINER=     obrien@FreeBSD.org

EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
MAN1=		detex.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/detex ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1}l ${PREFIX}/man/man1/${MAN1}


.include <bsd.port.mk>
