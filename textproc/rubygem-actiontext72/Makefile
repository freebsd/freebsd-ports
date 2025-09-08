PORTNAME=	actiontext
PORTVERSION=	7.2.2.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actiontext \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack72>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack72 \
		rubygem-activerecord72>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord72 \
		rubygem-activestorage72>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage72 \
		rubygem-activesupport72>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport72 \
		rubygem-globalid-rails72>=0.6.0:databases/rubygem-globalid-rails72 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.2\.

.include <bsd.port.mk>
