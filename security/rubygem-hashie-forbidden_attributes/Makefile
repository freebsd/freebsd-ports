# $FreeBSD$

PORTNAME=	hashie-forbidden_attributes
PORTVERSION=	0.1.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	tz@freebsd.org
COMMENT=	Hashie compatibility layer for forbidden attributes protection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BUILD_DEPENDS=	rubygem-grape>=0:devel/rubygem-grape \
		rubygem-minitest>=0:devel/rubygem-minitest \
		rubygem-rails4>=4.0:www/rubygem-rails4 \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3
RUN_DEPENDS=	rubygem-hashie>=3.0:devel/rubygem-hashie

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
