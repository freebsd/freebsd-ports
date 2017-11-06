# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nanoc
PORTVERSION=	4.7.14
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Simple but flexible static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cri>=2.3:devel/rubygem-cri \
		rubygem-ddplugin>=1.0:devel/rubygem-ddplugin \
		rubygem-hamster>=3.0:devel/rubygem-hamster \
		rubygem-ref>=2.0:devel/rubygem-ref \

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/nanoc

.include <bsd.port.mk>
