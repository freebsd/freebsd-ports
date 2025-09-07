PORTNAME=	activestorage
PORTVERSION=	8.0.2.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack80>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack80 \
		rubygem-activejob80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob80 \
		rubygem-activerecord80>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord80 \
		rubygem-activesupport80>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport80 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.0\.

.include <bsd.port.mk>
