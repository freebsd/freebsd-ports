# New ports collection makefile for:	xfaces-3.3
# Version required:	1.6.1
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
# With some 
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1996/12/17 05:08:34 asami Exp $
#

DISTNAME=	xfaces-3.3
CATEGORIES=	mail
# xfaces-sounds.tar.gz only in LOCAL_PORTS
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/xfaces/ \
		ftp://odie.physik2.uni-rostock.de/pub/ \
		ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/
DISTFILES=	${DISTNAME}.tar.Z xfaces-sounds.tar.gz
		
MAINTAINER=	Lars_Koeller@odie.physik2.uni-rostock.de

BUILD_DEPENDS= 	${X11BASE}/lib/libaudio.a:${PORTSDIR}/audio/nas
LIB_DEPENDS=	compface\\.1\\.:${PORTSDIR}/mail/faces

USE_IMAKE=	YES

pre-configure:
	@ln -sf ../sounds ${WRKSRC}

pre-install:
	@${MKDIR} ${LOCALBASE}/share/sounds

.include <bsd.port.mk>
