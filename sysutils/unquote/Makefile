# New ports collection makefile for:	unquote
# Date created:		5 May 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	unquote
PORTVERSION=	1.0.b3
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/misc/unquote/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org

MAN1=		unquote.1
MANCOMPRESSED=	yes

.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif

.include <bsd.port.mk>
