# New ports collection makefile for:	rubygem-innate
# Date created:		2010-01-20
# Whom:			Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	innate
PORTVERSION=	2010.04
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	Powerful web-framework wrapper for Rack

RUN_DEPENDS=	rubygem-rack=1.1.0:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/redirect.rb.patch
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -name "*.orig" -delete

.include <bsd.port.mk>
