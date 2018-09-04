# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	vttest
PORTVERSION=	2018.08.11
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.invisible-island.net/vttest/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,,g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Program to test "VT100-compatibility" of terminals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

MAKEFILE=	makefile

PLIST_FILES=	bin/vttest man/man1/vttest.1.gz

USES=		tar:tgz

.include <bsd.port.mk>
