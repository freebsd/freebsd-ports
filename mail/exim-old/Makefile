# New ports collection makefile for:	exim
# Version required:	1.58
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.4 1996/11/10 21:31:17 obrien Exp $
#

DISTNAME=	exim-1.58
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-1.58.tar.gz exim-texinfo-1.58.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	mkdir ${WRKSRC}/Local
	cp ${FILESDIR}/Makefile ${WRKSRC}/Local
	cp ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	(cd ${WRKSRC}/doc ; ln -s ../../exim-texinfo-1.58/doc/* )

.include <bsd.port.mk>
