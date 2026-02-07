PORTNAME=	unicorn-worker-killer
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Kill unicorn workers by memory and request counts
WWW=		https://github.com/kzk/unicorn-worker-killer

LICENSE=	GPLv2+ RUBY
LICENSE_COMB=	dual
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-get_process_mem0>=0<1:devel/rubygem-get_process_mem0 \
		rubygem-unicorn>=4<7:www/rubygem-unicorn

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
