# New ports collection makefile for:	mpeg_play
# Version required:	2.2
# Date created:		17 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.5 1995/04/09 07:09:37 asami Exp $
#

DISTNAME=	mpeg_play-2.2
CATEGORIES+=	graphics
MASTER_SITES=	ftp://s2k-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes

pre-patch:
	cp ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	cp ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
