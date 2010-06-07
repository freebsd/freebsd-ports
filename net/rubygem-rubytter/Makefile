# New ports collection makefile for:	rubygem-rubytter
# Date created:		2009-07-12
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rubytter
PORTVERSION=	1.3.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A simple twitter library

RUN_DEPENDS=	rubygem-json>=1.1.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-oauth>=0.3.6:${PORTSDIR}/net/rubygem-oauth

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
