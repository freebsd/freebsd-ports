# New ports collection makefile for:	exim
# Version required:	0.57
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.2 1996/07/09 21:24:41 asami Exp $
#

DISTNAME=	exim-0.57
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-0.57.tar.gz exim-texinfo-0.57.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	mkdir ${WRKSRC}/Local
	cp ${FILESDIR}/Makefile ${WRKSRC}/Local
	cp ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	(cd ${WRKSRC}/doc ; ln -s ../../exim-texinfo-0.57/doc/* )

.include <bsd.port.mk>
