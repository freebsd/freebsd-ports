PORTNAME=	mls
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	https://www.marki-online.net/MLS/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Program for generating various statistics on emails
WWW=		https://www.marki-online.net/MLS/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.gz

USES=		tar:tgz

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	mls

SUB_FILES=	pkg-message
PLIST_FILES=	bin/mls share/man/man1/mls.1.gz
PORTDATA=	html/bar.gif html/mls_class.php html/style_mls.css
PORTDOCS=	README.txt
PORTEXAMPLES=	README example.php forward procmailrc

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/html
.for f in ${PORTDATA}
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DATADIR}/html/
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/$f ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
