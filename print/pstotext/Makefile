# New ports collection makefile for:	pstotext
# Date created:		December 6, 1999
# Whom:			Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$
#

PORTNAME=	pstotext
PORTVERSION=	1.8g
CATEGORIES=	print
MASTER_SITES=	http://www.research.digital.com/SRC/virtualpaper/cgi-bin/nph-download.tcl/pstotext.tar.Z?object=pstotext
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ob@seicom.NET

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

MAN1=		pstotext.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstotext.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
