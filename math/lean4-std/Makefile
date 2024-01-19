PORTNAME=	lean4-std
DISTVERSIONPREFIX=	v
DISTVERSION=	4.5.0-rc1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lean4: Std library
WWW=		https://lean-lang.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lake:math/lean4

USE_GITHUB=	yes
GH_ACCOUNT=	leanprover
GH_PROJECT=	std4

NO_ARCH=	yes

do-build:
	@cd ${WRKSRC} && \
		lake build

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/lean
	cd ${WRKSRC}/.lake/build/lib && \
		${INSTALL_DATA} Std.olean ${STAGEDIR}${PREFIX}/lib/lean && \
		${COPYTREE_SHARE} Std ${STAGEDIR}${PREFIX}/lib/lean

.include <bsd.port.mk>
