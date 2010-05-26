# Ports collection makefile for:	rubygem-activeresource
# Date created:				30 Jan 2009
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	activeresource
PORTVERSION=	2.3.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A coherent wrapper object-relational mapping for REST web services

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/activesupport-${PORTVERSION}.gemspec:${PORTSDIR}/devel/rubygem-activesupport
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
