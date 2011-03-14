# ex:ts=8
# Ports collection makefile for:	psmark
# Date created:			Aug 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	psmark
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.antitachyon.com/download/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renders a vertical string on any PostScript document

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		psmark.1
PLIST_FILES=	bin/psmark

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psmark ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psmark.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
