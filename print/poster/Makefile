# Created by: Yoshiro MIHIRA <sanpei@sanpei.org>
# $FreeBSD$

PORTNAME=	poster
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ics.ele.tue.nl/pub/users/jos/poster/
DISTNAME=	poster

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resize a postscript image to print on larger media and/or multiple sheets

ALL_TARGET=	poster
MAKEFILE=	/dev/null
MAKE_ENV=	LDLIBS="-lm"
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/poster man/man1/poster.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
