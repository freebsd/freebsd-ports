PORTNAME=	carrierwave
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Upload files, map them to a range of ORMs, store on different backends

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel61>=4.0.0:databases/rubygem-activemodel61 \
		rubygem-activesupport61>=4.0.0:devel/rubygem-activesupport61 \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-ssrf_filter>=1.0<2:security/rubygem-ssrf_filter

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
