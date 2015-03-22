# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feedjira
PORTVERSION=	1.6.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Feed fetching and parsing library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-curb>=0.8:${PORTSDIR}/ftp/rubygem-curb \
		rubygem-loofah>=2.0:${PORTSDIR}/textproc/rubygem-loofah \
		rubygem-sax-machine>=1.0:${PORTSDIR}/textproc/rubygem-sax-machine

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
