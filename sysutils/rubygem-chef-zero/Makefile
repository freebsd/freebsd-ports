# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef-zero
PORTVERSION=	13.0.0
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi-yajl>=2.2:devel/rubygem-ffi-yajl \
		rubygem-hashie>=2.0:devel/rubygem-hashie \
		rubygem-mixlib-log>=1.3:devel/rubygem-mixlib-log \
		rubygem-rack>=2.0:www/rubygem-rack \
		rubygem-uuidtools>=2.1:devel/rubygem-uuidtools

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/chef-zero

.include <bsd.port.mk>
