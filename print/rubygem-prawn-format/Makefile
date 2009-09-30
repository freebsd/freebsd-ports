# Ports collection makefile for:	rubygem-prawn-format
# Date created:				19 June, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$

PORTNAME=	prawn-format
PORTVERSION=	0.2.1
CATEGORIES=	print rubygems
MASTER_SITES=	RF/prawn

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An extension of Prawn that allows inline formatting

BUILD_DEPENDS=	rubygem-prawn-core>=0:${PORTSDIR}/print/rubygem-prawn-core
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
