PORTNAME=	carrierwave
PORTVERSION=	1.3.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Upload files, map them to a range of ORMs, store on different backends
WWW=		https://github.com/carrierwaveuploader/carrierwave

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel-gitlab>=4.0.0:databases/rubygem-activemodel-gitlab \
		rubygem-activesupport-gitlab>=4.0.0:devel/rubygem-activesupport-gitlab \
		rubygem-mime-types-gitlab>=1.16:misc/rubygem-mime-types-gitlab \
		rubygem-ssrf_filter10>=1.0<1.1.0:security/rubygem-ssrf_filter10

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	carrierwave_project

.include <bsd.port.mk>
