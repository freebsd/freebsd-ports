# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	actiontext
PORTVERSION=	6.1.3.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Edit and display rich text in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-activerecord613>=${PORTVERSION}:databases/rubygem-activerecord613 \
		rubygem-activestorage613>=${PORTVERSION}:net/rubygem-activestorage613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-nokogiri>=1.8.5:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
