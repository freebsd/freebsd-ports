# New ports collection makefile for:	Yorick-doc
# Date created:         25 Jan 02
# Whom:                 David H. Munro <munro1@llnl.gov>
#
# $FreeBSD$
#

PORTNAME=	yorick-doc
PORTVERSION=	1.5.07
PORTREVISION=	1
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp-icf.llnl.gov/pub/Yorick/ \
		ftp://wuarchive.wustl.edu/languages/yorick/
DISTNAME=	yorick-doc
EXTRACT_SUFX=	.tgz

MAINTAINER=	munro1@llnl.gov

WRKSRC=		${WRKDIR}/doc

NO_BUILD=	true

do-install:
	@cd ${WRKSRC}; ${RM} -f yorick.pdf yorick-info.tgz download.html
	@if test ! -d ${DATADIR}; then ${MKDIR} ${DATADIR}; fi
	cd ${WRKSRC}; ${CP} -r * ${DATADIR}

.include <bsd.port.mk>
