# New ports collection makefile for:	exim
# Version required:	1.82
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.11 1997/10/15 20:49:46 markm Exp $
#

DISTNAME=	exim-1.82
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-1.82.tar.gz exim-texinfo-1.80.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Local
	@${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	@(cd ${WRKSRC}/doc ; \
	for i in ../../exim-texinfo-1.80/doc/* ; do \
		ln -sf $$i ; \
	done )

.include <bsd.port.mk>
