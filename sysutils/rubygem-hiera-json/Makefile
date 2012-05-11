# Ports collection makefile for:	hiera-json
# Date created:				10 May 2012
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hiera-json
PORTVERSION=	0.3.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A backend for Hiera that queries JSON data

RUN_DEPENDS=	puppet>=0:${PORTSDIR}/sysutils/puppet \
		rubygem-hiera>=0:${PORTSDIR}/sysutils/rubygem-hiera \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
