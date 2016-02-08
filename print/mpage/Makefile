# Created by: Kapil Chowksey
# $FreeBSD$

# To override mpage's default paper size of A4, set PAGESIZE to another
# page type.  Some common values include "Letter" (8.5" x 11") and
# "Legal" (8.5" x 14").

PORTNAME=	mpage
PORTVERSION=	2.5.6
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print multiple pages per sheet of paper

USES=		tar:tgz
ALL_TARGET=	default

PORTDOCS=	CHANGES Characters Copyright Encoding.format FAQ NEWS \
		README README.OS2 README.amiga SCOPTIONS TODO
PLIST_FILES=	bin/mpage %%DATADIR%%/CP850.PC %%DATADIR%%/ISO+STD+OTH \
		%%DATADIR%%/ISO-8859.1 %%DATADIR%%/ISO-8859.15 \
		%%DATADIR%%/ISO-Latin.1 %%DATADIR%%/ISO-Latin.2 \
		man/man1/mpage.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
