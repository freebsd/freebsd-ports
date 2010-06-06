# Ports collection makefile for:	rubygem-anemone
# Date created:				2010-04-11
# Whom:					niels <niels@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	anemone
PORTVERSION=	0.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	niels@FreeBSD.org
COMMENT=	Anemone is a library that allows programs to spider websites

RUN_DEPENDS=	rubygem-nokogiri>=1.3.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-robots>=0.8.0:${PORTSDIR}/www/rubygem-robots

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/anemone

.include <bsd.port.mk>
