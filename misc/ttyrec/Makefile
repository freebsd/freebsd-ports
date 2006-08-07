# ex:ts=8
# New ports collection makefile for:   ttyrec
# Date created:                Feb 14, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttyrec
PORTVERSION=	1.0.8
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tty recorder

USE_GCC=	3.4+

MAN1=	ttyplay.1 ttyrec.1

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" \
		${WRKSRC}/Makefile

do-install:
.for file in ttyrec ttyplay ttytime
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${TARGETDIR}/bin
.endfor
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${file} ${MAN1PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
