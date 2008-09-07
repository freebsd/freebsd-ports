# New ports collection makefile for:	humanzip
# Date created:		21 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	humanzip
PORTVERSION=	0.5
CATEGORIES=	textproc archivers
MASTER_SITES=	SAVANNAH CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compresses text to human readable output

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|;s|-O2|${CFLAGS}|' \
		${WRKSRC}/${MAKEFILE}

MAN1=	${PORTNAME}.1
MLINKS=	${PORTNAME}.1 humanunzip.1
PLIST_FILES=	bin/${PORTNAME} bin/humanunzip
PORTDOCS=	CHANGELOG README TODO

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/human*zip ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
