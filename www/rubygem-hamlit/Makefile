# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hamlit
PORTVERSION=	2.14.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High Performance Haml Implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-temple>=0.8.2:devel/rubygem-temple \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

USES=		gem shebangfix
USE_RUBY=	yes

PLIST_FILES=	bin/hamlit

SHEBANG_FILES=	bin/ruby bin/setup bin/test

.include <bsd.port.mk>
