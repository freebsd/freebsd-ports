# $FreeBSD$

PORTNAME=	direnv
PORTVERSION=	2.11.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Environment variable manager for your shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	zimbatm

USES=		gmake

PLIST_FILES=	bin/direnv man/man1/direnv.1.gz man/man1/direnv-stdlib.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/direnv \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/direnv.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/direnv-stdlib.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
