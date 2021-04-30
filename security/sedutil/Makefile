PORTNAME=	sedutil
PORTVERSION=	1.12
CATEGORIES=	security

MAINTAINER=	ken@FreeBSD.org
COMMENT=	Self Encrypting Drive utility

LICENSE=	GPLv3+

USES=		gmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	kendmerry
GH_PROJECT=	sedutil
GH_TAGNAME=	3122ba0

BUILD_WRKSRC=	${WRKSRC}/freebsd/CLI
ALL_TARGET=	build

PLIST_FILES+=	bin/sedutil-cli
SEDUTIL_SD=	${BUILD_WRKSRC}/dist/Release/CLang-Generic
SEDUTIL_PROG=	sedutil-cli

do-install:
	${INSTALL_PROGRAM} ${SEDUTIL_SD}/${SEDUTIL_PROG} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
