# New ports collection makefile for:	metamail
# Version required:	2.7
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1995/04/23 12:47:03 asami Exp $
#

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES+=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-install:
	gzip -9nf ${PREFIX}/man/man1/audiocompose.1 \
	${PREFIX}/man/man1/audiosend.1 ${PREFIX}/man/man1/extcompose.1 \
	${PREFIX}/man/man1/getfilename.1 ${PREFIX}/man/man1/mailto-hebrew.1 \
	${PREFIX}/man/man1/mailto.1 ${PREFIX}/man/man1/metamail.1 \
	${PREFIX}/man/man1/metasend.1 ${PREFIX}/man/man1/mime.1 \
	${PREFIX}/man/man1/mimencode.1 ${PREFIX}/man/man1/mmencode.1 \
	${PREFIX}/man/man1/patch-metamail.1 ${PREFIX}/man/man1/richtext.1 \
	${PREFIX}/man/man1/showaudio.1 ${PREFIX}/man/man1/showexternal.1 \
	${PREFIX}/man/man1/shownonascii.1 ${PREFIX}/man/man1/showpartial.1 \
	${PREFIX}/man/man1/showpicture.1 ${PREFIX}/man/man1/splitmail.1 \
	${PREFIX}/man/man4/mailcap.4

.include <bsd.port.mk>
