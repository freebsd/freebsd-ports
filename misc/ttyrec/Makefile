# ex:ts=8
# New ports collection makefile for:   ttyrec
# Date created:                Feb 14, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttyrec
PORTVERSION=	1.0.6
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/ttyrec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tty recorder

USE_REINPLACE=	yes
MAN1=	ttyplay.1 ttyrec.1

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" \
		${WRKSRC}/Makefile

do-install:
.for file in ttyrec ttyplay ttytime
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file} ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
