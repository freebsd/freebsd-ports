# New ports collection makefile for:	rubygem-uglifier
# Date created:		2011-09-12
# Whom:			Steve Wills <swills@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uglifier
PORTVERSION=	1.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Ruby wrapper for UglifyJS JavaScript compressor

RUN_DEPENDS=	rubygem-execjs>=1.2.4:${PORTSDIR}/devel/rubygem-execjs \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
