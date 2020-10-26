# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	bundler
PORTVERSION=	1.17.3
CATEGORIES=	sysutils rubygems
PKGNAMESUFFIX=	1
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/bundle1 bin/bundler1

post-install:
		${MV} ${STAGEDIR}${PREFIX}/bin/bundle ${STAGEDIR}${PREFIX}/bin/bundle1
		${MV} ${STAGEDIR}${PREFIX}/bin/bundler ${STAGEDIR}${PREFIX}/bin/bundler1

.include <bsd.port.mk>
