PORTNAME=	libfyaml
DISTVERSION=	0.9
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/pantoniou/libfyaml/releases/download/v${DISTVERSION}/

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

TEST_TARGET=	check # one test fails, see https://github.com/pantoniou/libfyaml/issues/103

post-patch:
	@${GREP} -rl "#include <alloca\\.h>" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -E "s|#include <alloca\\.h>|#include <stdlib.h>|"

.include <bsd.port.mk>
