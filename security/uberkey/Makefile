# New ports collection makefile for:	uberkey
# Date created:		2007-10-29
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	uberkey
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.linuks.mine.nu/uberkey/ LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A keylogger for x86 systems

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386
MAN8=		uberkey.8
PLIST_FILES=	bin/uberkey

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} *.c -o ${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN8} ${MAN1PREFIX}/man/man8

.include <bsd.port.mk>
