# New ports collection makefile for:	unquote
# Date created:		5 May 2000
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	unquote
PORTVERSION=	1.0.b2
CATEGORIES=	sysutils
MASTER_SITES=	http://ringwraith.online.bg/~roam/devel/misc/unquote/ \
		http://people.FreeBSD.org/~roam/devel/misc/unquote/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		unquote.1

MAKE_ENV+=	NOMANCOMPRESS=yes
.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif

.include <bsd.port.mk>
