# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sinatra-r18n
PORTVERSION=	2.0.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sinatra extension that provides i18n support to your web application

LICENSE=	LGPL3

RUN_DEPENDS=	rubygem-r18n-core=${PORTVERSION}:${PORTSDIR}/devel/rubygem-r18n-core \
		rubygem-sinatra>=1.3:${PORTSDIR}/www/rubygem-sinatra

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
