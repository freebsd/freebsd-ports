# Ports collection makefile for:	rubygem-rightflexiscale
# Date created:			23 Apr 2009
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rightflexiscale
PORTVERSION=	0.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
DISTNAME=	right_flexiscale-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides Ruby access to the Flexiscale API

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.4:${PORTSDIR}/net/rubygem-righthttpconnection \
		rubygem-soap4r>=1.5.8:${PORTSDIR}/devel/rubygem-soap4r

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
UNIQUENAME=	${PORTNAME}

.include <bsd.port.mk>
