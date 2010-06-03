# New ports collection makefile for:    retail
# Date created:                         19 May 2010
# Whom:                                 Oleg Ginzburg
#
# $FreeBSD$
#

PORTNAME=	retail
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://xjack.org/retail/download/ \
		http://itdev.spb.ru/mirror/

MAINTAINER=	oleg.ginzburg@nevosoft.ru
COMMENT=	A program for incremental logfile reader

GNU_CONFIGURE=	yes
MAN1=		retail.1
PLIST_FILES=	bin/retail

post-configure:
	${REINPLACE_CMD} -e 's/%.o: %.c \*.h ..\/config.h//g' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/retail.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
