# New ports collection makefile for:	apsfilter
# Version required: 	4.9.3
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.21 1998/06/27 05:19:20 asami Exp $
#

DISTNAME=	apsfilter-4.9.8
CATEGORIES=	print
MASTER_SITES=	http://www.FreeBSD.ORG/~andreas/download/

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript5 \
		html2ps:${PORTSDIR}/print/html2ps \
		transfig:${PORTSDIR}/print/transfig \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		anytopnm:${PORTSDIR}/graphics/netpbm

NO_PACKAGE=	"Too many questions"
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/apsfilter

.include <bsd.port.mk>
