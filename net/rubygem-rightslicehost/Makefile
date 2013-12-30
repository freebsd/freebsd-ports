# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rightslicehost
PORTVERSION=	0.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
DISTNAME=	right_slicehost-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides Ruby access to the Slicehost API

RUN_DEPENDS=	rubygem-righthttpconnection>=1.2.4:${PORTSDIR}/net/rubygem-righthttpconnection

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes
UNIQUENAME=	${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
