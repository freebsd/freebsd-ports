# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.5 1995/11/27 04:05:46 asami Exp $
#

DISTNAME=	vic-2.8
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

LIB_DEPENDS=	tk41:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
USE_X11=	yes

install:
	${INSTALL_PROGRAM} ${WRKSRC}/vic ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/histtolut ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vic.1 ${PREFIX}/man/man1
	${COMPRESS_MAN} ${PREFIX/man/man1/vic.1
	
.include <bsd.port.mk>
