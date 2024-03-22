PORTNAME=	vttest
PORTVERSION=	2023.12.30
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://invisible-island.net/archives/${PORTNAME}/ \
		https://invisible-mirror.net/archives/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,,g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Program to test "VT100-compatibility" of terminals
WWW=		https://invisible-island.net/vttest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

MAKEFILE=	makefile

PLIST_FILES=	bin/vttest \
		share/man/man1/vttest.1.gz

.include <bsd.port.mk>
