# New ports collection makefile for:	exim
# Version required:	1.92
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.12 1998/02/09 14:32:28 markm Exp $
#

DISTNAME=	exim-1.92
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-1.92.tar.gz exim-texinfo-1.90.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

USE_PERL5=	YES

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Local
	@${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	@(cd ${WRKSRC}/doc ; \
	for i in ../../exim-texinfo-1.90/doc/* ; do \
		ln -sf $$i ; \
	done )

.include <bsd.port.mk>
