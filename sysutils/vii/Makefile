# New ports collection makefile for:	vii
# Date created:				12 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	vii
PORTVERSION=	4.0
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Execute a command repeatedly and scroll the output

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/vii
MAN1=		vii.1

MAKE_ARGS+=	CFLAGS="${CFLAGS}"

LICENSE=	GPLv2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
