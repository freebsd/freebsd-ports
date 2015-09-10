# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	less
PORTVERSION=	1.2.21
#PORTREVISION=	0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	The LESS Ruby gem compiles LESS code to CSS

RUN_DEPENDS=	rubygem-treetop>=1.4.2:${PORTSDIR}/devel/rubygem-treetop \
		rubygem-mutter>=0.4.2:${PORTSDIR}/devel/rubygem-mutter

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/lessc

.include <bsd.port.mk>
