# New ports collection makefile for:	ffe
# Date created:		19 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ffe
PORTVERSION=	0.2.0
CATEGORIES=	textproc
MASTER_SITES=	SFE/ff-extractor

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Flat file extractor

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MAN1PREFIX}/man
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
PORTDOCS=	${PORTNAME}.html

post-patch:
	@${REINPLACE_CMD} -e 's/^install-data-am: install-htmlDATA install-info-am install-man/install-data-am: install-man/' ${WRKSRC}/doc/Makefile.in

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
