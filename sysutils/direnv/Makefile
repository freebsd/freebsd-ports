PORTNAME=	direnv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.33.0
PORTREVISION=	1
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
		man/man1/direnv-stdlib.1.gz \
		man/man1/direnv.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/direnv \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/direnv.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/direnv-stdlib.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
