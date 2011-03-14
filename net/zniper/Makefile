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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display and reset active TCP connections

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ARGS=	CFLAGS="${CFLAGS}" CC="${CC}"
ALL_TARGET=	fbsd_x86
PLIST_FILES=	bin/${PORTNAME}
MAN1=	${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
