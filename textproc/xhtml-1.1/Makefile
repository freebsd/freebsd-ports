# New ports collection makefile for:	XHTML 1.1 DTD
# Date created:				18 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	xhtml
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.w3.org/TR/xhtml11/
DISTNAME=	xhtml11
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	W3C's XHTML 1.1 DTD

WRKSRC=		${WRKDIR}/xhtml11-20010531
NO_BUILD=	yes
DTDDIR=		${PREFIX}/share/xml/${PORTNAME}/${PORTVERSION}

do-install:
	${MKDIR} ${DTDDIR}
	${INSTALL_DATA} ${WRKSRC}/DTD/* ${DTDDIR}

.include <bsd.port.mk>
