# New ports collection makefile for:	exim
# Version required:	1.61
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.8 1997/02/26 13:45:02 markm Exp $
#

DISTNAME=	exim-1.70
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-1.70.tar.gz exim-texinfo-1.70.tar.gz

PATCH_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
PATCHFILES=	exim-1.70.patches

MAINTAINER=	markm@FreeBSD.ORG

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Local
	@${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	@(cd ${WRKSRC}/doc ; \
	for i in ../../exim-texinfo-1.70/doc/* ; do \
		ln -sf $$i ; \
	done )

.include <bsd.port.mk>
