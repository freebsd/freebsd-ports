# New ports collection makefile for:	rubygem-ramaze
# Date created:		2010-01-20
# Whom:			Jyun-Yan You <jyyou@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	ramaze
PORTVERSION=	2009.10
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jyyou@cs.nctu.edu.tw
COMMENT=	Ramaze is a simple and modular web framework

RUN_DEPENDS=	rubygem-innate=2009.10:${PORTSDIR}/www/rubygem-innate

PLIST_FILES=	bin/ramaze

USE_RUBY=	yes

USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${PATCH} -p0 -d ${PREFIX}/${GEM_LIB_DIR} < ${PATCHDIR}/xhtml.rb.patch
	@${FIND} ${PREFIX}/${GEM_LIB_DIR} -name "*.orig" -delete

.include <bsd.port.mk>
