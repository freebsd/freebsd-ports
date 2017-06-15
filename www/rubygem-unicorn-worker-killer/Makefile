# $FreeBSD$

PORTNAME=	unicorn-worker-killer
PORTVERSION=	0.4.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Kill unicorn workers by memory and request counts

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-get_process_mem>=0:devel/rubygem-get_process_mem \
		rubygem-unicorn>=4:www/rubygem-unicorn

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
