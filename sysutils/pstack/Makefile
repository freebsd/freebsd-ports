# Created by: Peter Edwards <pmedwards@eircom.net>
# $FreeBSD$

PORTNAME=	pstack
PORTVERSION=	1.3
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Retrieve process/core file stack traces

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	z0nt
GH_TAGNAME=	874a052
USES=		uidfix
ONLY_FOR_ARCHS=	amd64 i386
CONFLICTS=	pstacku-[0-9]*
MAKE_ARGS+=	BINDIR=${PREFIX}/bin
MAKE_ARGS+=	MANDIR=${PREFIX}/man/man
MAKE_ARGS+=	LIBDIR=${PREFIX}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
