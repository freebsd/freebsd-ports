# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guard-livereload
PORTVERSION=	2.5.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically reloads your browser when 'view' files are modified

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-em-websocket>=0.5:${PORTSDIR}/www/rubygem-em-websocket \
		rubygem-guard>=2.8:${PORTSDIR}/sysutils/rubygem-guard \
		rubygem-guard-compat>=1.0:${PORTSDIR}/sysutils/rubygem-guard-compat \
		rubygem-multi_json>=1.8:${PORTSDIR}/devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
