# New ports collection makefile for:	rubygem-guard-livereload
# Date created:		2011-10-20
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	guard-livereload
PORTVERSION=	0.3.1
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically reloads your browser when 'view' files are modified

RUN_DEPENDS=	rubygem-em-websocket>=0.2.0:${PORTSDIR}/www/rubygem-em-websocket \
		rubygem-guard>=0.4.0:${PORTSDIR}/sysutils/rubygem-guard \
		rubygem-multi_json>=1.0.3:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
