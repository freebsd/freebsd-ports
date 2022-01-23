# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	actiontext
PORTVERSION=	7.0.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=${PORTVERSION}:www/rubygem-actionpack70 \
		rubygem-activerecord70>=${PORTVERSION}:databases/rubygem-activerecord70 \
		rubygem-activestorage70>=${PORTVERSION}:net/rubygem-activestorage70 \
		rubygem-activesupport70>=${PORTVERSION}:devel/rubygem-activesupport70 \
		rubygem-globalid-rails70>=0.6.0:databases/rubygem-globalid-rails70 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.0\.

.include <bsd.port.mk>
