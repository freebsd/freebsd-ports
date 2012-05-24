# New ports collection makefile for:   ttyrec
# Date created:                Feb 14, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttyrec
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Tty recorder

PLIST_FILES=	bin/ttyplay \
		bin/ttyrec \
		bin/ttytime

MAN1=	ttyplay.1 ttyrec.1
BINS=	ttyplay ttyrec ttytime

OPTIONS=	OPENPTY "Use openpty instead" off

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1

.if defined(WITH_OPENPTY)
CFLAGS+=	-DHAVE_openpty -lutil
.endif

.include <bsd.port.post.mk>
