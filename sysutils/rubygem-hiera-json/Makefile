# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hiera-json
PORTVERSION=	0.4.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	mat@FreeBSD.org
COMMENT=	A backend for Hiera that queries JSON data

RUN_DEPENDS=	puppet>=0:${PORTSDIR}/sysutils/puppet \
		rubygem-hiera>=1.0:${PORTSDIR}/sysutils/rubygem-hiera \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
