# ex:ts=8
# Ports collection makefile for:	psmark
# Date created:			Aug 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	psmark
PORTVERSION=	2.0
CATEGORIES=	print
MASTER_SITES=	http://www.antitachyon.com/download/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Renders a vertical string on any PostScript document

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes

MAN1=	psmark.1

post-patch:
	@${REINPLACE_CMD} -e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psmark ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psmark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
