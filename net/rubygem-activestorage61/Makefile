PORTNAME=	activestorage
PORTVERSION=	6.1.7.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack61 \
		rubygem-activejob61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob61 \
		rubygem-activerecord61>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord61 \
		rubygem-activesupport61>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport61 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
