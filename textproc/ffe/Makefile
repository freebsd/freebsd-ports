# New ports collection makefile for:	ffe
# Date created:		19 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffe
PORTVERSION=	0.2.8
CATEGORIES=	textproc
MASTER_SITES=	SF/ff-extractor/ff-extractor/${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Flat file extractor

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	${PORTNAME}.html

post-patch:
	@${REINPLACE_CMD} -e 's/^install-data-am: install-htmlDATA install-info-am install-man/install-data-am: install-man/' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|setmode|setmode123|g' ${WRKSRC}/configure

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/doc/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
