PORTNAME=	bundler
PORTVERSION=	2.7.1
PORTEPOCH=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications
WWW=		https://bundler.io/ \
		https://github.com/rubygems/rubygems/tree/master/bundler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe gem

NO_ARCH=	yes

CONFLICTS_INSTALL=	go-tools # bin/bundle

post-install:
.for i in 1 5
	for f in ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/bundler/man/*.${i}; do \
		${GZIP_CMD} $${f}; \
		${RLN} $${f}.gz ${STAGEDIR}${PREFIX}/share/man/man${i}/$$(basename $${f}).gz; \
	done
.endfor

.include <bsd.port.mk>
