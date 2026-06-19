PORTNAME=	libfyaml
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/pantoniou/libfyaml/releases/download/v${DISTVERSION}/

PATCH_SITES=	https://github.com/pantoniou/libfyaml/commit/
PATCHFILES=	0982fcefc6a16d4c8cb5b06747d3fc8e630de3ae.diff:-p1 \
		9192deaac095f9881cc1e5756dede683f36b09d6.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	YAML parser and emitter
WWW=		https://github.com/pantoniou/libfyaml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	git:devel/git \
		bash:shells/bash

USES=		gmake libtool shebangfix # will change to cmake soon
USE_LDCONFIG=	yes

SHEBANG_FILES=	test/testemitter.test

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check

post-patch:
	${GREP} -rl "#include <alloca\\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -E "s|#include <alloca\\.h>|#include <stdlib.h>|"

.include <bsd.port.mk>
