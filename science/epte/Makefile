# New ports collection makefile for:	epte
# Date created:				2010-09-01
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	epte
PORTVERSION=	2.0.8
CATEGORIES=	science
MASTER_SITES=	http://www.toddmiller.com/epte/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Electronic Periodic Table of the Elements

MAKEFILE=	makefile
ALL_TARGET=	${PORTNAME}

MAN1=		epte.1
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/epte

post-patch:
	@${REINPLACE_CMD} 's|/usr|${PREFIX}|' ${WRKSRC}/epte.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/epte ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/epte.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
