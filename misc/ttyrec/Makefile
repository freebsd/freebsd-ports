# ex:ts=8
# New ports collection makefile for:   ttyrec
# Date created:                Feb 14, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttyrec
PORTVERSION=	1.0.2
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/ttyrec/

MAINTAINER=	ijliao@FreeBSD.org

do-install:
.for file in ttyrec ttyplay
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
