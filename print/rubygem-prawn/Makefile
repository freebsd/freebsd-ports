# Ports collection makefile for:	rubygem-prawn
# Date created:				29 Oct 2008
# Whom:					wenheping@gmail.com
#
# $FreeBSD$

PORTNAME=	prawn
PORTVERSION=	0.5.1
CATEGORIES=	print rubygems
MASTER_SITES=	RF/prawn

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast pure Ruby PDF generator

BUILD_DEPENDS=	rubygem-prawn-layout>=0.2.0.1:${PORTSDIR}/print/rubygem-prawn-layout \
		rubygem-prawn-format>=0.2.0.1:${PORTSDIR}/print/rubygem-prawn-format \
		rubygem-prawn-core>=0.5.0.1:${PORTSDIR}/print/rubygem-prawn-core
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
