PORTNAME=	actiontext
PORTVERSION=	6.0.6
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actiontext \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack60 \
		rubygem-activerecord60>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord60 \
		rubygem-activestorage60>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage60 \
		rubygem-activesupport60>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport60 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.0\.

.include <bsd.port.mk>
