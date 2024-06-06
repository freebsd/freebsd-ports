PORTNAME=	actiontext
PORTVERSION=	7.0.8.4
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actiontext \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack70 \
		rubygem-activerecord70>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport70 \
		rubygem-globalid-rails70>=0.6.0:databases/rubygem-globalid-rails70 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
