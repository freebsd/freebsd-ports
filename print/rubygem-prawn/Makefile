# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	prawn
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast pure Ruby PDF generator

LICENSE=	RUBY GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pdf-core07>=0.7.0<0.8:print/rubygem-pdf-core07 \
		rubygem-ttfunk>=1.5<2:print/rubygem-ttfunk

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
