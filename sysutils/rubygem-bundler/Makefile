PORTNAME=	bundler
PORTVERSION=	2.4.15
PORTEPOCH=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications
WWW=		https://bundler.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/bundle \
		bin/bundler

CONFLICTS_INSTALL=	go-tools # bin/bundle

.include <bsd.port.mk>
