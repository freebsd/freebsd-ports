# New ports collection makefile for:	pdfoutline
# Date created:		4 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdfoutline
PORTVERSION=	0.0.${DATE:S/-//g}
DISTVERSION=	2.4
CATEGORIES=	textproc
MASTER_SITES=	SF/fntsample
DISTNAME=	fntsample-${DISTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Add outlines to PDF files

RUN_DEPENDS=	p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2

USE_PERL5_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
DATE=		2007-03-14

post-patch:
	@${SED} -e 's|@DATE@|2007-03-14|' ${WRKSRC}/${PORTNAME}.1.in > ${WRKSRC}/${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
