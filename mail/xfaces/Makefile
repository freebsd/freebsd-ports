# New ports collection makefile for:	xfaces-3.3
# Version required:	1.6.1
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
# With some 
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1996/12/14 22:33:02 andreas Exp $
#

DISTNAME=	xfaces-3.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/xfaces/ \
		ftp://odie.physik2.uni-rostock.de/pub/
		
MAINTAINER=	Lars_Koeller@odie.physik2.uni-rostock.de

BUILD_DEPENDS= 	${X11BASE}/lib/libaudio.a:${PORTSDIR}/audio/nas
LIB_DEPENDS=	compface:${PORTSDIR}/mail/faces

EXTRACT_SUFX=	.tar.Z

USE_X11=	YES
USE_IMAKE=	YES

pre-configure:
	@(cd ${WRKSRC}; tar xvzf ${FILESDIR}/sounds.tar.gz)

pre-install:
	@mkdir -p /usr/local/share/sounds

.include <bsd.port.mk>
