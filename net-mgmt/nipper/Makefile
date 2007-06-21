# New ports collection makefile for:	nipper
# Date created:		3 May 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nipper
PORTVERSION=	0.10.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Netdev config analyzer

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	Changelog Readme TODO Features.txt Options.txt Quickstart.txt \
		XML.txt

post-extract:
	@${MV} ${WRKSRC}/docs/* ${WRKSRC}/

do-build:
	@cd ${WRKSRC}/ && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
