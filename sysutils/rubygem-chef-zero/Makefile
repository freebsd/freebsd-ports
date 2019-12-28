# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef-zero
PORTVERSION=	13.1.0
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-hashie>=2.0<4.0:devel/rubygem-hashie \
		rubygem-mixlib-log>=1.3<2:devel/rubygem-mixlib-log \
		rubygem-rack>=2.0,3<3,3:www/rubygem-rack \
		rubygem-uuidtools>=2.1<3:devel/rubygem-uuidtools

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/chef-zero

.include <bsd.port.mk>
