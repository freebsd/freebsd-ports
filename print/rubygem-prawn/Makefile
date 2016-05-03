# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	prawn
PORTVERSION=	2.1.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast pure Ruby PDF generator

LICENSE=	RUBY GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPLv2
LICENSE_FILE_GPLv3=	${WRKSRC}/GPLv3
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-pdf-core>=0.6.1:print/rubygem-pdf-core \
		rubygem-ttfunk>=1.4.0:print/rubygem-ttfunk

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
