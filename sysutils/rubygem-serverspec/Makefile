# Created by: Yuichiro NAITO <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	serverspec
PORTVERSION=	2.41.5
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Test suite for server configuration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-rspec>=3.0:devel/rubygem-rspec \
		rubygem-rspec-its>=1.2.0:devel/rubygem-rspec-its \
		rubygem-specinfra>=2.72:sysutils/rubygem-specinfra

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/serverspec-init

.include <bsd.port.mk>
