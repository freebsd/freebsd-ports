# New ports collection makefile for:	multitail
# Date created:				10 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	multitail
PORTVERSION=	2.9.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vanheusden.com/multitail/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Tail multiple files on console with ncurses

USE_REINPLACE=	yes

MAN1=		multitail.1

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d ; /^CFLAGS/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/multitail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/multitail.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
