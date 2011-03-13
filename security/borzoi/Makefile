# ex:ts=8
# New ports collection makefile for:	borZoi
# Date created:			Aug 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	borzoi
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://dragongate-technologies.com/borzoi/
DISTNAME=	borZoi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Elliptic Curve Cryptography Library

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
RUN_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
