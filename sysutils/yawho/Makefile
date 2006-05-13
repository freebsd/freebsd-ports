# New ports collection makefile for:	yawho
# Date created:		16 December 2000
# Whom:			Daniel Harris <dannyboy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yawho
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://wizard.ae.krakow.pl/~mike/download/

MAINTAINER=	dannyboy@FreeBSD.org
COMMENT=	Simple 'w'-like program; displays connection type and login shell PID

PLIST_FILES=	bin/yawho

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500014
pre-patch:
	@${REINPLACE_CMD} -E -e 's/kp_.?proc\.._/ki_/' ${WRKSRC}/process.c
.endif

GNU_CONFIGURE=	yes

.include <bsd.port.post.mk>
