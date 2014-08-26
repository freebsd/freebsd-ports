# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	unquote
PORTVERSION=	1.0.b4
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/misc/unquote/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Execute a command with safely quoted arguments

USES=		uidfix

PLIST_FILES=	bin/unquote man/man1/unquote.1.gz

.if		!defined(NO_RELEASE)
MAKE_ENV+=	RELEASE=yes
.endif

.include <bsd.port.mk>
