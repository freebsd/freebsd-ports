# New ports collection makefile for:	trn
# Version required:	3.6
# Date created:		21 October 1994
# Whom:			smace
#
# $Id$
#

DISTNAME=	trn-3.6
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.uu.net/networking/news/readers/trn/

IS_INTERACTIVE=	yes

RUN_DEPENDS=  munpack:${PORTSDIR}/mail/mpack

pre-configure:
	@echo "===> Running pre-configure target for ${DISTNAME}"
	@sh ${SCRIPTDIR}/preconf ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.mk>
