PORTNAME=	rabbitmqadmin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	dch@FreeBSD.org
COMMENT=	CLI for managing RabbitMQ via HTTP API
WWW=		https://github.com/rabbitmq/rabbitmqadmin-ng

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	compilation fails: ld: error: undefined symbol: __atomic_load

USES=		cargo llvm pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	rabbitmq
GH_PROJECT=	rabbitmqadmin-ng

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib/libclang.so

PLIST_FILES=	bin/rabbitmqadmin

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
