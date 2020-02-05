# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	actiontext
PORTVERSION=	6.0.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	60

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BROKEN_RUBY24=	yes

RUN_DEPENDS=	rubygem-actionpack60>=${PORTVERSION}:www/rubygem-actionpack60 \
		rubygem-activerecord60>=${PORTVERSION}:databases/rubygem-activerecord60 \
		rubygem-activestorage60>=${PORTVERSION}:net/rubygem-activestorage60 \
		rubygem-activesupport60>=${PORTVERSION}:devel/rubygem-activesupport60 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
