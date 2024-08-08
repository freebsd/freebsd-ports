PORTNAME=	puma_worker_killer
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Automatically restart Puma cluster workers based on max RAM available
WWW=		https://github.com/schneems/puma_worker_killer

LICENSE=	MIT

RUN_DEPENDS=	rubygem-get_process_mem0>=0.2<1:devel/rubygem-get_process_mem0 \
		rubygem-puma>=2.7:www/rubygem-puma

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
