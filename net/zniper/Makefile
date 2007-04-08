# New ports collection makefile for:	zniper
# Date created:		8 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zniper
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	CENKES
# Unversioned distfile available from:
# http://www.signedness.org/tools/zniper.tgz

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Display and reset active TCP connections

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	CFLAGS="${CFLAGS}" CC="${CC}"
ALL_TARGET=	fbsd_x86
PLIST_FILES=	bin/${PORTNAME}
MAN1=	${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
