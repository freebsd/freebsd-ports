PORTNAME=	activestorage
PORTVERSION=	7.1.5.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack71 \
		rubygem-activejob71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob71 \
		rubygem-activerecord71>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
