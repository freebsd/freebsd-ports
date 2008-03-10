# New ports collection makefile for:   ttyrec
# Date created:                Feb 14, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttyrec
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Tty recorder

PLIST_FILES=	bin/ttyplay \
		bin/ttyrec \
		bin/ttytime

MAN1=	ttyplay.1 ttyrec.1
BINS=	ttyplay ttyrec ttytime

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
