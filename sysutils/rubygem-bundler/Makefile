# Created by: Robert Gogolok <gogo@cs.uni-sb.de>

PORTNAME=	bundler
DISTVERSION=	2.3.5
PORTEPOCH=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe gem
USE_RUBY=	yes

CONFLICTS_INSTALL=	go-tools # bin/bundle

NO_ARCH=	yes

PLIST_FILES=	bin/bundle \
		bin/bundler

.include <bsd.port.mk>
