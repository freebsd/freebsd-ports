# To override mpage's default paper size of A4, set PAGESIZE to another
# page type.  Some common values include "Letter" (8.5" x 11") and
# "Legal" (8.5" x 14").

PORTNAME=	mpage
DISTVERSION=	2.5.8
CATEGORIES=	print
MASTER_SITES=	http://www.mesa.nl/pub/mpage/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print multiple pages per sheet of paper
WWW=		https://www.mesa.nl/download.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
ALL_TARGET=	default

PORTDOCS=	CHANGES Characters Copyright Encoding.format FAQ NEWS \
		README SCOPTIONS TODO
PLIST_FILES=	bin/mpage ${DATADIR}/CP850.PC ${DATADIR}/ISO+STD+OTH \
		${DATADIR}/ISO-8859.1 ${DATADIR}/ISO-8859.15 \
		${DATADIR}/ISO-Latin.1 ${DATADIR}/ISO-Latin.2 \
		share/man/man1/mpage.1.gz

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
