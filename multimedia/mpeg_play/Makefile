# New ports collection makefile for:	mpeg_play
# Version required:	2.4
# Date created:		17 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.10 1998/05/25 08:05:14 tg Exp $
#

DISTNAME=	mpeg_play-2.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.ORG

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes
MAN1=		mpeg_play.1

pre-patch:
	cp ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	cp ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
