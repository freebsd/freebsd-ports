# ex:ts=8
# New ports collection makefile for:	borZoi
# Date created:			Aug 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	borzoi
PORTVERSION=	1.0.1
CATEGORIES=	security
MASTER_SITES=	http://dragongate-technologies.com/borzoi/
DISTNAME=	borZoi-${PORTVERSION}

MAINTAINER=	jim@corebsd.or.id

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
RUN_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
