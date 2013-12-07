# Created by: Eric Freeman <freebsdports@chillibear.com>
# $FreeBSD$

PORTNAME=	feedzirra
PORTVERSION=	0.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Feed fetching and parsing library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-curb>=0.8.1:${PORTSDIR}/ftp/rubygem-curb \
		rubygem-loofah>=1.2.1:${PORTSDIR}/textproc/rubygem-loofah \
		rubygem-sax-machine>=0.2.1:${PORTSDIR}/textproc/rubygem-sax-machine

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
