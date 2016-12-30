# Created by: Torsten Zuehlsdorff <tz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hamlit
PORTVERSION=	2.7.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	High Performance Haml Implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-temple>=0.7.6:devel/rubygem-temple \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/hamlit

.include <bsd.port.mk>
