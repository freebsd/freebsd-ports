# Created by: Shin-ya MURAKAMI <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	ruby-dcl
PORTVERSION=	1.7.0.2
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Ruby interface to the scientific graphic library DCL

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	rubygem-narray>=0.5.5:math/rubygem-narray
LIB_DEPENDS=	libcdcl.so:science/cdcl
RUN_DEPENDS=	rubygem-narray>=0.5.5:math/rubygem-narray \
		rubygem-narray_miss>0:math/rubygem-narray_miss

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USES=		gem

.include <bsd.port.mk>
