# FreeBSD ports collection makefile for: apsfilter
# Version required: 	4.9.3
# Date created: 	Tue Nov 14 18:29:48 MET 1995
# Whom: 		Andreas Klemm <andreas@knobel.gun.de>
#
# $Id$
#

DISTNAME=	apsfilter-4.9.3
CATEGORIES+=	print
MASTER_SITES=	ftp://freefall.FreeBSD.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=	Andreas Klemm <andreas@knobel.gun.de>

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript \
		transfig:${PORTSDIR}/print/transfig \
		cjpeg:${PORTSDIR}/graphics/jpeg \
		anytopnm:${PORTSDIR}/graphics/netpbm

NO_CONFIGURE=	yes
NO_PACKAGE=	yes	# too many questions
IS_INTERACTIVE=	yes
WRKSRC=		${WRKDIR}/apsfilter

.include <bsd.port.mk>
