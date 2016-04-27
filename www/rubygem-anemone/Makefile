# Created by: niels <niels@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anemone
PORTVERSION=	0.7.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Library that allows programs to spider websites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nokogiri>=1.3.0:textproc/rubygem-nokogiri \
		rubygem-robotex>=1.0.0:www/rubygem-robotex

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/anemone

.include <bsd.port.mk>
