# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.7 1996/11/07 02:15:09 fenner Exp $
#

DISTNAME=	vic-2.8
CATEGORIES+=	mbone
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

LIB_DEPENDS=	tk41:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
USE_X11=	yes

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut
	${COMPRESS_MAN} ${PREFIX}/man/man1/vic.1
	
.include <bsd.port.mk>
