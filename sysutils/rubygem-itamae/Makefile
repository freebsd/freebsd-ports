# Created by: Yuichiro NAITO <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	itamae
PORTVERSION=	1.9.13
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Simple and lightweight configuration management tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-ansi>=0:devel/rubygem-ansi \
		rubygem-hashie>=0:devel/rubygem-hashie \
		rubygem-schash>=0.1.0:devel/rubygem-schash \
		rubygem-specinfra>=2.64.0:sysutils/rubygem-specinfra \
		rubygem-thor>=0:devel/rubygem-thor

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/itamae

.include <bsd.port.mk>
