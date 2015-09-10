# Created by: Jyun-Yan You <jyyou@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	ramaze
PORTVERSION=	2012.12.08
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ramaze is a simple and modular web framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-innate>=2012.12:${PORTSDIR}/www/rubygem-innate \
		rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake

#USE_RAKE=	yes
NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/ramaze

.include <bsd.port.mk>
