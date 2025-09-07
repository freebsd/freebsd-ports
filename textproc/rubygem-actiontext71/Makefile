PORTNAME=	actiontext
PORTVERSION=	7.1.5.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications
WWW=		https://github.com/rails/rails/tree/main/actiontext \
		https://rubyonrails.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack71>=${PORTVERSION}<${PORTVERSION}_99:www/rubygem-actionpack71 \
		rubygem-activerecord71>=${PORTVERSION}<${PORTVERSION}_99:databases/rubygem-activerecord71 \
		rubygem-activestorage71>=${PORTVERSION}<${PORTVERSION}_99:net/rubygem-activestorage71 \
		rubygem-activesupport71>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-activesupport71 \
		rubygem-globalid-rails71>=0.6.0:databases/rubygem-globalid-rails71 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.1\.

.include <bsd.port.mk>
