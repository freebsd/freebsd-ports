# Ports collection makefile for:	rubygem-mechanize
# Date created:				5 Feb 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mechanize
PORTVERSION=	0.9.3
CATEGORIES=	www rubygems
MASTER_SITES=	RF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

BUILD_DEPENDS=	rubygem-hpricot>=0.5.0:${PORTSDIR}/www/rubygem-hpricot \
		rubygem-hoe>=1.5.0:${PORTSDIR}/devel/rubygem-hoe \
		rubygem-nokogiri>=1.2.1:${PORTSDIR}/textproc/rubygem-nokogiri
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
