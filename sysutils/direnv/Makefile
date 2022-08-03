PORTNAME=	direnv
PORTVERSION=	2.27.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Environment variable manager for your shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake go:modules
USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/direnv/direnv
MAKE_ENV=	GOPATH=${WRKSRC}
MAKEFILE=	GNUmakefile

GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		direnv:go-dotenv:4cce6d1a66f7:direnv_go_dotenv/vendor/github.com/direnv/go-dotenv \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:sys:b77594299b42:golang_sys/vendor/golang.org/x/sys \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty

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
