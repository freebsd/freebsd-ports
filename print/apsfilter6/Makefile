# FreeBSD ports collection makefile for: apsfilter
# Version required: 	4.9.3
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1996/10/19 09:11:07 andreas Exp $
#

DISTNAME=	apsfilter-4.9.3
CATEGORIES+=	print
MASTER_SITES=	ftp://freefall.FreeBSD.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	andreas@klemm.gtn.com

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript4 \
		transfig:${PORTSDIR}/print/transfig \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		anytopnm:${PORTSDIR}/graphics/netpbm

NO_CONFIGURE=	yes
NO_PACKAGE=	yes	# too many questions
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/apsfilter

pre-clean:
	@(cd ${PORTSDIR}/print/ghostscript4	; ${MAKE} clean)
	@(cd ${PORTSDIR}/print/transfig		; ${MAKE} clean)
	@(cd ${PORTSDIR}/graphics/jpeg		; ${MAKE} clean)
	@(cd ${PORTSDIR}/graphics/netpbm	; ${MAKE} clean)

.include <bsd.port.mk>
