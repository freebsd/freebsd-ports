# New ports collection makefile for:   respond
# Date created:                                8 January 2008
# Whom:                                        Jouke Witteveen <j.witteveen@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	respond
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	j.witteveen@gmail.com
COMMENT=	A response automator for logged events

PLIST_FILES=	bin/${PORTNAME}
MAN1=		respond.1
MANCOMPRESSED=	maybe

MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANEXT=${MANEXT} \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
