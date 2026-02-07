PORTNAME=	carrierwave
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Upload files, map them to a range of ORMs, store on different backends
WWW=		https://github.com/carrierwaveuploader/carrierwave

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel70>=4.0.0:databases/rubygem-activemodel70 \
		rubygem-activesupport70>=4.0.0:devel/rubygem-activesupport70 \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-ssrf_filter10>=1.0<1.1.0:security/rubygem-ssrf_filter10

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	carrierwave_project

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
