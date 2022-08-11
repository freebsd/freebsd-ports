PORTNAME=	chef-zero
PORTVERSION=	15.0.11
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-hashie4>=2.0<5.0:devel/rubygem-hashie4 \
		rubygem-mixlib-log>=2.0<4.0:devel/rubygem-mixlib-log \
		rubygem-rack>=2.0.6,3<3,3:www/rubygem-rack \
		rubygem-uuidtools>=2.1<3:devel/rubygem-uuidtools \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/chef-zero

.include <bsd.port.mk>
