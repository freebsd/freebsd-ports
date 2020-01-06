# $FreeBSD$

PORTNAME=	sbase
DISTVERSION=	g20171110
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.suckless.org/sbase/snapshot/
DISTNAME=	${PORTNAME}-4b9c664

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Collection of UNIX tools that are portable across UNIX-like systems

BROKEN=		unfetchable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_ARGS=	PREFIX=${PREFIX}/${PORTNAME} MANPREFIX="${PREFIX}/${PORTNAME}/man"
MANDIRS=	${PREFIX}/${PORTNAME}/man

.include <bsd.port.mk>
