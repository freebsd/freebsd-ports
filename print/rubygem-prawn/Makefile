# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	prawn
PORTVERSION=	1.3.0
CATEGORIES=	print rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast pure Ruby PDF generator

LICENSE=	RUBY GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-pdf-core>=0.4.0:${PORTSDIR}/print/rubygem-pdf-core \
		rubygem-ttfunk>=1.4.0:${PORTSDIR}/print/rubygem-ttfunk

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
