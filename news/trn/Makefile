# New ports collection makefile for:	trn
# Version required:	3.5
# Date created:		21 October 1994
# Whom:			smace
#
# $id: Makefile,v 1.0 1994/10/21 00:00:00 smace Exp $
#

DISTNAME=	trn-3.5
MASTER_SITES=	ftp://ftp.uu.net/networking/news/readers/trn/
EXTRACT_SUFX=	.tar.gz
DISTFILES=	trn-3.5.tar.gz

IS_INTERACTIVE=	yes

pre-configure:
	@echo "===> Running pre-configure target for ${DISTNAME}"
	@sh ${SCRIPTDIR}/preconf ${PORTSDIR} ${.CURDIR} ${WRKSRC}

.include <bsd.port.mk>
