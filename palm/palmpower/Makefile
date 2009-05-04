# New ports collection makefile for:	palmpower
# Date Created:				22 Aug 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	palmpower
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	http://ftp.linux.in.th/palm/develope/ \
		http://ftp.ksu.edu.tw/FTP/FreeBSD/distfiles/ \
		${MASTER_SITE_OPENBSD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Disassembler and other tools for PalmOS binaries

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		pilotdis.1

PLIST_FILES=	bin/pila bin/pilotdis bin/splitprc

post-build:
	cd ${WRKSRC}/utils; ${CC} ${CFLAGS} -o splitprc splitprc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/pila/pila ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/pilotdis/pilotdis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/utils/splitprc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pilotdis.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
