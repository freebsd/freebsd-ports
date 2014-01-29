# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffe
PORTVERSION=	0.3.3
CATEGORIES=	textproc
MASTER_SITES=	SF/ff-extractor/ff-extractor/${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Flat file extractor

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	${PORTNAME}.html

post-patch:
	@${REINPLACE_CMD} -e 's/^install-data-am: install-htmlDATA install-info-am install-man/install-data-am: install-man/' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|setmode|setmode123|g' ${WRKSRC}/configure

post-install:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
