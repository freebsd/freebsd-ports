PORTNAME=	puma_worker_killer
PORTVERSION=	0.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Automatically restart Puma cluster workers based on max RAM available

LICENSE=	MIT

RUN_DEPENDS=	rubygem-get_process_mem>=0.2:devel/rubygem-get_process_mem \
		rubygem-puma>=2.7:www/rubygem-puma

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
