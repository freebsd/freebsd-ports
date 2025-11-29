PORTNAME=	activestorage
PORTVERSION=	8.1.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack81 \
		rubygem-activejob81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob81 \
		rubygem-activerecord81>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord81 \
		rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
