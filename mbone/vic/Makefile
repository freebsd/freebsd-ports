# New ports collection makefile for:	vic
# Version required:	2.6
# Date created:		14 December 1994
# Whom:			wollman
#
# $Id: Makefile,v 1.13 1998/02/24 21:43:36 jseger Exp $
#

DISTNAME=	vic-2.8
CATEGORIES=	mbone tk80
MASTER_SITES=	ftp://ftp.ee.lbl.gov/conferencing/vic/
DISTFILES=	vicsrc-2.8.tar.gz

MAINTAINER=	fenner@FreeBSD.ORG

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		vic.1

post-install:
	strip ${PREFIX}/bin/vic
	strip ${PREFIX}/bin/histtolut

.include <bsd.port.mk>
