# New ports collection makefile for:	apsfilter
# Version required: 	4.9.3
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.22 1998/07/04 20:31:40 andreas Exp $
#

DISTNAME=	apsfilter-4.9.9
CATEGORIES=	print
MASTER_SITES=	http://www.FreeBSD.ORG/~andreas/download/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5 \
		html2ps:${PORTSDIR}/print/html2ps \
		transfig:${PORTSDIR}/print/transfig \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		anytopnm:${PORTSDIR}/graphics/netpbm \
		bunzip2:${PORTSDIR}/archivers/bzip2

NO_PACKAGE=	"Too many questions"
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/apsfilter

.include <bsd.port.mk>
