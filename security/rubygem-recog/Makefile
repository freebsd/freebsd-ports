# $FreeBSD$

PORTNAME=	recog
PORTVERSION=	1.0.7
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Framework for fingerprinting products

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/recog_export.rb \
		bin/recog_match.rb \
		bin/recog_verify.rb

PORTSCOUT=	ignore:1

.include <bsd.port.mk>
