PORTNAME=	activestorage
PORTVERSION=	6.0.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-activejob60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob60 \
		rubygem-activerecord60>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord60 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
