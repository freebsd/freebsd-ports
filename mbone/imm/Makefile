# New ports collection makefile for:	imm
# Version required:	3.3
# Date created:		13 October 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.7 1996/11/07 12:25:45 asami Exp $
#

DISTNAME=	imm-3.3
CATEGORIES+=	mbone
MASTER_SITES=	ftp://ftp.ucs.ed.ac.uk/pub/videoconference/imm/
DISTFILES=	imm.src.tar.Z

LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

BROKEN=		yes	# depends on tk-3.6
WRKSRC=		${WRKDIR}/src

.include <bsd.port.mk>
