PORTNAME=	direnv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.34.0
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Environment variable manager for your shell
WWW=		https://direnv.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		go:modules
GO_MODULE=	github.com/direnv/direnv/v2

PLIST_FILES=	bin/direnv \
		share/man/man1/direnv-stdlib.1.gz \
		share/man/man1/direnv.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/direnv \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/direnv.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/direnv-stdlib.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
