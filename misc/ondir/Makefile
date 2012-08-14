# New ports collection makefile for:	ondir
# Date created:		2010-01-24
# Whom:			ports@c0decafe.net <ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	ondir
PORTVERSION=	0.2.2
CATEGORIES=	misc
MASTER_SITES=	http://swapoff.org/files/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatically executes scripts as you traverse directories

ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	PREFIX=${PREFIX} CONF=${PREFIX}/etc/ondirrc
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
