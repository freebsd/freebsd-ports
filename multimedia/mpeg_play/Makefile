# New ports collection makefile for:	mpeg_play
# Version required:	2.3
# Date created:		17 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.6 1996/02/07 09:28:22 asami Exp $
#

DISTNAME=	mpeg_play-2.3
CATEGORIES+=	graphics
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/multimedia/mpeg/play/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/mpeg_play
USE_IMAKE=	yes

pre-patch:
	cp ${WRKSRC}/Imakefile.proto ${WRKSRC}/Imakefile
	cp ${WRKSRC}/mpeg_play.1 ${WRKSRC}/mpeg_play.man

.include <bsd.port.mk>
