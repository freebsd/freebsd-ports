# Created by: Eric Freeman <freebsdports@chillibear.com>

PORTNAME=	mail
PORTVERSION=	2.7.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby email handler

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-mini_mime>=0.1.1:mail/rubygem-mini_mime \
		rubygem-net-smtp>0:mail/rubygem-net-smtp

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
