PORTNAME=	reflex
PORTVERSION=	20230523
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://invisible-mirror.net/archives/reflex/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Relocalizable fast lexical scanner
WWW=		https://invisible-island.net/reflex/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
			--mandir=${PREFIX}/share/man
TEST_TARGET=	bigcheck

.include <bsd.port.mk>
