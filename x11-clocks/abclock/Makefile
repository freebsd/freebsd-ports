# New ports collection makefile for:	abclock
# Date created:				15 August 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abclock
PORTVERSION=	1.0c
CATEGORIES=	x11-clocks
MASTER_SITES=	http://odur.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clock for X that displays hours and minutes in an analog fashion

PLIST_FILES=	bin/abclock bin/abc_img

USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${PREFIX}/bin

.include <bsd.port.mk>
