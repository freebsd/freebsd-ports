PORTNAME=	prawn
PORTVERSION=	2.4.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	24

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast, tiny, and nimble PDF generator for Ruby
WWW=		https://prawnpdf.org/ \
		https://github.com/prawnpdf/prawn

LICENSE=	RUBY GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pdf-core09>=0.9.0<0.10:print/rubygem-pdf-core09 \
		rubygem-ttfunk>=1.7<2:print/rubygem-ttfunk

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.4\.

.include <bsd.port.mk>
