PORTNAME=	activestorage
PORTVERSION=	7.0.6
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications
WWW=		https://github.com/rails/rails/tree/main/activestorage \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack70 \
		rubygem-activejob70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activejob70 \
		rubygem-activerecord70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70 \
		rubygem-marcel>=1.0<2:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
