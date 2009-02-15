# Ports collection makefile for:	rubygem-prawn
# Date created:				29 Oct 2008
# Whom:					wenheping@gmail.com
#
# $FreeBSD$

PORTNAME=	prawn
PORTVERSION=	0.4.1
CATEGORIES=	print rubygems
MASTER_SITES=	RF/prawn

MAINTAINER=	wenheping@gmail.com
COMMENT=	Fast pure Ruby PDF generator

BUILD_DEPENDS=	rubygem-prawn-layout>=0.1.0:${PORTSDIR}/print/rubygem-prawn-layout
RUN_DEPENDS=	rubygem-prawn-layout>=0.1.0:${PORTSDIR}/print/rubygem-prawn-layout

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
