# New ports collection makefile for:	vii
# Date created:				12 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	vii
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	http://vii.sourceforge.net/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Execute a command repeatedly and scroll the output

GNU_CONFIGURE=	yes
MAKE_ARGS+=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/vii
MAN1=		vii.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
