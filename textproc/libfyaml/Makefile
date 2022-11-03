PORTNAME=	libfyaml
DISTVERSION=	0.7.12
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

TEST_TARGET=	check # one test fails, see https://github.com/pantoniou/libfyaml/issues/60

.include <bsd.port.mk>
