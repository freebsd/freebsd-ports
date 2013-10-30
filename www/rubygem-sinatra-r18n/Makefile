# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sinatra-r18n
PORTVERSION=	1.1.6
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra extension that provides i18n support to your web application

RUN_DEPENDS=	rubygem-sinatra>=1.3:${PORTSDIR}/www/rubygem-sinatra \
		rubygem-r18n-core=${PORTVERSION}:${PORTSDIR}/devel/rubygem-r18n-core

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes


.include <bsd.port.mk>
