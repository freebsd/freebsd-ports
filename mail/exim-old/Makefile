# New ports collection makefile for:	exim
# Version required:	0.53
# Date created:		23 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.1.1.1 1996/07/06 11:13:57 markm Exp $
#

DISTNAME=	exim-0.53
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/
DISTFILES=	exim-0.53.tar.gz exim-texinfo-0.52.gz
EXTRACT_ONLY=	exim-0.53.tar.gz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	exim-0.53.patch
PATCH_DIST_STRIP=	-p2

MAINTAINER=	markm@FreeBSD.ORG

post-extract:
	@cp ${DISTDIR}/exim-texinfo-0.52.gz ${WRKSRC}/doc
	@gunzip ${WRKSRC}/doc/exim-texinfo-0.52

do-configure:
	mkdir ${WRKSRC}/Local
	cp ${FILESDIR}/Makefile ${WRKSRC}/Local
	cp ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	-(cd ${WRKSRC}; make)

.include <bsd.port.mk>
