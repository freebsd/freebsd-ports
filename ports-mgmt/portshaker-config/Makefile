# New ports collection makefile for:	portshaker-config
# Date created:		2010-04-29
# Whom:			Romain Tartiere <romain@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	portshaker-config
CATEGORIES=	ports-mgmt

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Simple configuration manager for portshaker

BUILD_DEPENDS=	portshaker:${PORTSDIR}/ports-mgmt/portshaker
RUN_DEPENDS=	${BUILD_DEPENDS}

MASTERDIR=	${.CURDIR}/../portshaker
BUILD_WRKSRC=	${WRKSRC}/examples
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
