# New ports collection makefile for:	uni2ascii
# Date created:				12 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	uni2ascii
PORTVERSION=	3.8
CATEGORIES=	textproc
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert between UTF-8 Unicode and 7-bit ASCII equivalents

GNU_CONFIGURE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		uni2ascii.1 ascii2uni.1
PLIST_FILES=	bin/uni2ascii bin/ascii2uni

do-install:
.for f in ${PORTNAME} ascii2uni
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
