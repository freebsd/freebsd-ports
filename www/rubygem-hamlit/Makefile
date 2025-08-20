PORTNAME=	hamlit
PORTVERSION=	3.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High Performance Haml Implementation
WWW=		https://github.com/k0kubun/hamlit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-temple>=0.8.2:devel/rubygem-temple \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

USES=		gem shebangfix

PLIST_FILES=	bin/hamlit

SHEBANG_FILES=	bin/ruby bin/setup bin/test

.include <bsd.port.mk>
