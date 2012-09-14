# New ports collection makefile for:	rubygem-fluentd
# Date created:		10 Jul 2012
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluentd
PORTVERSION=	0.10.25
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Fluent event collector

RUN_DEPENDS=	\
	rubygem-msgpack>=0.4.4:${PORTSDIR}/devel/rubygem-msgpack \
	rubygem-json>=1.4.3:${PORTSDIR}/devel/rubygem-json \
	rubygem-yajl-ruby>=1.0:${PORTSDIR}/devel/rubygem-yajl-ruby \
	rubygem-cool.io>=1.1.0:${PORTSDIR}/devel/rubygem-cool.io \
	rubygem-http_parser.rb>=0.5.1:${PORTSDIR}/net/rubygem-http_parser.rb

BROKEN=		conflicting dependencies

USE_RUBY=	yes
RUBY_VER=	1.9
USE_RUBYGEMS=	yes
PLIST_FILES=	bin/fluent-cat bin/fluent-gem bin/fluentd
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
