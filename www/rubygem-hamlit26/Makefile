# $FreeBSD$

PORTNAME=	hamlit
PORTVERSION=	2.6.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	26

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	High Performance Haml Implementation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-temple07>=0.7.6:devel/rubygem-temple07 \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

CONFLICTS_INSTALL=	rubygem-hamlit
PORTSCOUT=	limit:^2\.6\.

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	bin/setup bin/test bin/ruby

PLIST_FILES=	bin/hamlit

.include <bsd.port.mk>
