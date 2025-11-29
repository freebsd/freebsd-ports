PORTNAME=	actiontext
PORTVERSION=	8.1.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actiontext \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-action_text-trix>=2.1.15<2.2:textproc/rubygem-action_text-trix \
		rubygem-actionpack81>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack81 \
		rubygem-activerecord81>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord81 \
		rubygem-activestorage81>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage81 \
		rubygem-activesupport81>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport81 \
		rubygem-globalid-rails81>=0.6.0:databases/rubygem-globalid-rails81 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.1\.

.include <bsd.port.mk>
