# New ports collection makefile for:	bfilter
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bfilter
PORTVERSION=	0.8.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Smart filtering HTTP proxy

GNU_CONFIGURE=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.mk>
