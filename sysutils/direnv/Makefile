PORTNAME=	direnv
PORTVERSION=	2.32.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Environment variable manager for your shell
WWW=		https://direnv.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake go
USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/direnv/direnv
GH_TUPLE=	\
		BurntSushi:toml:v1.2.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		golang:mod:v0.5.1:golang_mod/vendor/golang.org/x/mod \
		golang:sys:bc2c85ada10a:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty

MAKEFILE=	GNUmakefile
MAKE_ENV=	GOPATH=${WRKSRC}

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
