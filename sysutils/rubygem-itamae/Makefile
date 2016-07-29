# Created by: Yuichiro NAITO <naito.yuichiro@gmail.com>
# $FreeBSD$

PORTNAME=	itamae
PORTVERSION=	1.9.9
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Simple and lightweight configuration management tool

LICENSE=	MIT

RUN_DEPENDS=	\
	rubygem-thor>=0:devel/rubygem-thor \
	rubygem-specinfra>=2.37.0:sysutils/rubygem-specinfra \
	rubygem-hashie>=0:devel/rubygem-hashie \
	rubygem-ansi>=0:devel/rubygem-ansi \
	rubygem-schash>=0.1.0:devel/rubygem-schash

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/itamae

.include <bsd.port.mk>
