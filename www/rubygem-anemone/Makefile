# Created by: niels <niels@FreeBSD.org>
# $FreeBSD$

PORTNAME=	anemone
PORTVERSION=	0.7.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Anemone is a library that allows programs to spider websites

RUN_DEPENDS=	rubygem-nokogiri>=1.3.0:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-robotex>=1.0.0:${PORTSDIR}/www/rubygem-robotex

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/anemone

.include <bsd.port.mk>
