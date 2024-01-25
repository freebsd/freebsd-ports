PORTNAME=	orch
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kevans.dev/kevans/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

PATCH_DIST_STRIP=	-p1
PATCH_SITES=	https://git.kevans.dev/kevans/orch/commit/

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Program orchestration tool scripted with lua
WWW=		https://git.kevans.dev/kevans/orch

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake lua:53-54

OPTIONS_DEFINE=		EXAMPLES MANPAGES
OPTIONS_DEFAULT=	EXAMPLES MANPAGES
OPTIONS_SUB=	yes

EXAMPLES_CMAKE_BOOL=	EXAMPLES
MANPAGES_CMAKE_BOOL=	MANPAGES

WRKSRC=		${WRKDIR}/${PORTNAME}

TEST_TARGET=	check

.include <bsd.port.mk>
