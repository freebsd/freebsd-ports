# New ports collection makefile for:	mpage
# Date created:		19 February 1998
# Whom:			Kapil Chowksey
#
# $FreeBSD$
#

# To override mpage's default paper size of A4, set PAGESIZE to another
# page type.  Some common values include "Letter" (8.5" x 11") and
# "Legal" (8.5" x 14").

PORTNAME=	mpage
PORTVERSION=	2.5.6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print multiple pages per sheet of paper

ALL_TARGET=	default

MAN1=		mpage.1
PORTDOCS=	CHANGES Characters Copyright Encoding.format FAQ NEWS \
		README README.OS2 README.amiga SCOPTIONS TODO
PLIST_FILES=	bin/mpage %%DATADIR%%/CP850.PC %%DATADIR%%/ISO+STD+OTH \
		%%DATADIR%%/ISO-8859.1 %%DATADIR%%/ISO-8859.15 \
		%%DATADIR%%/ISO-Latin.1 %%DATADIR%%/ISO-Latin.2
PLIST_DIRS=	%%DATADIR%%

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
