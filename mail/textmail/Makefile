# New ports collection makefile for:	textmail
# Date created:		8 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	textmail
PORTVERSION=	20070803
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://raf.org/textmail/ CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts e-mail attachments to plain-text

RUN_DEPENDS=	antiword:${PORTSDIR}/textproc/antiword \
		catdoc:${PORTSDIR}/textproc/catdoc \
		xls2csv:${PORTSDIR}/textproc/catdoc \
		lynx:${PORTSDIR}/www/lynx \
		pdftotext:${PORTSDIR}/graphics/xpdf

USE_PERL5=	yes
PLIST_FILES=	bin/${PORTNAME}
NO_WRKSUBDIR=	yes
MAN1=	${PORTNAME}.1

do-build:
	@cd ${WRKSRC}/&&pod2man ${PORTNAME}>${PORTNAME}.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
