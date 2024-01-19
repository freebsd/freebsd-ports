PORTNAME=	fastforward
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fastforward handles qmail forwarding according to a cdb database
WWW=		https://cr.yp.to/fastforward.html

USES=		gmake groff

ALL_TARGET=	default

FILES=	fastforward printforward setforward newaliases printmaillist setmaillist newinclude

PORTDOCS=	ALIASES

PLIST_FILES=	${FILES:S,^,bin/,} \
		${FILES:S,^,share/man/man1/,:S,$,.1.gz,}

OPTIONS_DEFINE=	DOCS

do-install:
.for binfile in ${FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${binfile} ${STAGEDIR}${PREFIX}/bin/${binfile}
	${INSTALL_MAN} ${WRKSRC}/${binfile}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ALIASES ${STAGEDIR}${DOCSDIR}/ALIASES

.include <bsd.port.mk>
