# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard-livereload
PORTVERSION=	1.1.3
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically reloads your browser when 'view' files are modified

RUN_DEPENDS=	rubygem-em-websocket>=0.2.0:${PORTSDIR}/www/rubygem-em-websocket \
		rubygem-guard>=1.5.0:${PORTSDIR}/sysutils/rubygem-guard \
		rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
