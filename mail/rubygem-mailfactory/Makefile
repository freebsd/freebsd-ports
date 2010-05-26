# Ports collection makefile for:	mailfactory
# Date created:				8 Oct 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mailfactory
PORTVERSION=	1.4.0
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A simple to use module for generating RGC compliant MIME mail

BUILD_DEPENDS=	rubygem-mime-types>=1.13.1:${PORTSDIR}/misc/rubygem-mime-types
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
