# $FreeBSD$

PORTNAME=	direnv
PORTVERSION=	2.21.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Environment variable manager for your shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	direnv
GH_SUBDIR=	src/github.com/direnv/direnv
MAKE_ENV=	GOPATH=${WRKSRC}
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/direnv man/man1/direnv.1.gz man/man1/direnv-stdlib.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/direnv \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/direnv.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/direnv-stdlib.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
