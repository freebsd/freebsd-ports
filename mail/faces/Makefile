# New ports collection makefile for:	faces-1.6.1
# Version required:	1.6.1
# Date created:		09 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
#			Andreas Klemm <andreas@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1997/11/17 18:47:53 max Exp $
#

DISTNAME=	faces-1.6.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.indiana.edu/pub/faces/faces/
EXTRACT_SUFX=	.tar.Z
		
MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

WRKSRC=		$(WRKDIR)/faces
MAN1=		compface.1 faces.1 face_update.1
MAN3=		compface.3 

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	@${RM} ${PREFIX}/man/man1/uncompface.1 ${PREFIX}/man/man3/uncompface.3
	@ln -fs compface.1.gz ${PREFIX}/man/man1/uncompface.1.gz
	@ln -fs compface.3.gz ${PREFIX}/man/man3/uncompface.3.gz
.endif

.include <bsd.port.mk>
