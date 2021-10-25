# Created by: Robert Gogolok <gogo@cs.uni-sb.de>

PORTNAME=	bundler
PORTVERSION=	1.17.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Tool that manages gem dependencies for Ruby applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/bundle1 bin/bundler1

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/bundle ${STAGEDIR}${PREFIX}/bin/bundle1
	${MV} ${STAGEDIR}${PREFIX}/bin/bundler ${STAGEDIR}${PREFIX}/bin/bundler1

.include <bsd.port.mk>
