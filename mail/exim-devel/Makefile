# New ports collection makefile for:	exim
# Version required:	0.57
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.3 1996/10/31 19:25:50 markm Exp $
#

DISTNAME=	exim-0.57
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-0.57.tar.gz exim-texinfo-0.57.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	mkdir ${WRKSRC}/Local
	cp ${FILESDIR}/Makefile ${WRKSRC}/Local
	cp ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	(cd ${WRKSRC}/doc ; ln -s ../../exim-texinfo-0.57/doc/* )

.include <bsd.port.mk>
