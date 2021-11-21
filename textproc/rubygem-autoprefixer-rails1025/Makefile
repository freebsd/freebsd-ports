PORTNAME=	autoprefixer-rails
PORTVERSION=	10.2.5.1
CATEGORIES=	textproc ruby
MASTER_SITES=	RG
PKGNAMESUFFIX=	1025

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parse CSS and add vendor prefixes to CSS rules

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-execjs>=0:devel/rubygem-execjs

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^10\.2\.5\.

.include <bsd.port.mk>
