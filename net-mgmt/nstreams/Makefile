# New ports collection makefile for:	nstreams
# Date created:		22 September 1999
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	nstreams
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/nstreams/download/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN1=		nstreams.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nstreams ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nstreams.1 ${MANPREFIX}/man/man1
.for file in nstreams-networks nstreams-services
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${PREFIX}/etc/${file}.sample
.endfor

.include <bsd.port.mk>
