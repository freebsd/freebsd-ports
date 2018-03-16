# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hamlit
PORTVERSION=	2.8.7
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High Performance Haml Implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-temple>=0.8.0:devel/rubygem-temple \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

CONFLICTS_INSTALL=	rubygem-hamlit26

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	bin/setup bin/test bin/ruby

PLIST_FILES=	bin/hamlit

.include <bsd.port.mk>
