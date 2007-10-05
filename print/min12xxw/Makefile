# New ports collection makefile for:	min12xxw
# Date created:		29 September 2007
# Whom:			Tim McCormick <tim@pcbsd.org>
#
# $FreeBSD$
#

PORTNAME=	min12xxw
PORTVERSION=	0.0.9
CATEGORIES=	print
MASTER_SITES=	http://hinterbergen.de/mala/min12xxw/

MAINTAINER=	tim@pcbsd.org
COMMENT=	Print driver for the Minolta PagePro 1(2/3/4)xxW printers

HAS_CONFIGURE=	yes

MAN1=		min12xxw.1
PLIST_FILES=	bin/min12xxw bin/esc-m

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/min12xxw ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/esc-m ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/min12xxw.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
