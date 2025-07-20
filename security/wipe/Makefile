PORTNAME=	wipe
PORTVERSION=	2.3.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	mauroeldritch@gmail.com
COMMENT=	File and block device wiping utility
WWW=		https://wipe.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/wipe share/man/man1/wipe.1.gz
PORTDOCS=	CHANGES README TESTING TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|@CFLAGS@|${CFLAGS}|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/doc/wipe|${DOCSDIR}|' ${WRKSRC}/wipe.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
