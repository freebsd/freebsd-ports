# New ports collection makefile for:	sublib
# Date created:				12 May 2008
# Whom:				Marcin Simonides <marcin@studio4plus.com>
#
# $FreeBSD$
#

PORTNAME=	sublib
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	multimedia textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle handling library for .NET/Mono

DEPRECATED=     Upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

USE_ZIP=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
