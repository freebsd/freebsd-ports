# New ports collection makefile for:	exim
# Version required:	1.60
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.7 1996/12/01 07:12:08 markm Exp $
#

DISTNAME=	exim-1.60
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-1.60.tar.gz exim-texinfo-1.60.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Local
	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	(cd ${WRKSRC}/doc ; \
	for i in ../../exim-texinfo-1.60/doc/* ; do \
		ln -sf $$i ; \
	done )

.include <bsd.port.mk>
