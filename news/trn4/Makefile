# New ports collection makefile for:	trn
# Version required:	3.6
# Date created:		21 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.10 1996/11/22 11:53:51 asami Exp $
#

DISTNAME=	trn-3.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/readers/trn/

RUN_DEPENDS=  munpack:${PORTSDIR}/mail/mpack

NO_PACKAGE=	"Too many questions."
IS_INTERACTIVE=	yes
MAN1=		trn.1 Pnews.1 Rnmail.1 newsetup.1 newsgroups.1

pre-configure:
	@echo "===> Running pre-configure target for ${DISTNAME}"
	@sh ${SCRIPTDIR}/preconf ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.mk>
