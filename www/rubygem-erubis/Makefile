# Ports collection makefile for:	rubygem-erubis
# Date created:				8 Oct 2008
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	erubis
PORTVERSION=	2.6.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@freebsd.org
COMMENT=	A fast, secure, and very extensible implementation of eRuby

BUILD_DEPENDS=	rubygem-abstract>=1.0.0:${PORTSDIR}/devel/rubygem-abstract
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/erubis

.include <bsd.port.mk>
