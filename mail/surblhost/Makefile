# New ports collection makefile for:	surblhost
# Date created:		20 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	surblhost
PORTVERSION=	0.8.0
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Check if a hostname is blacklisted

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/${PORTNAME}
MAN1=		${PORTNAME}.1
CONFIGURE_ARGS=	--mandir=${MAN1PREFIX}/man

.include <bsd.port.mk>
