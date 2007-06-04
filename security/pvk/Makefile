# New ports collection makefile for:	pvk
# Date created:				6 June 2007
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvk
PORTVERSION=	20070406
CATEGORIES=	security
MASTER_SITES=	http://www.drh-consultancy.demon.co.uk/
DISTNAME=	pvksrc
EXTRACT_SUFX=	.tgz.bin

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Tool to convert a RSA key in PEM format into a PVK file and vice versa

WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pvk ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
