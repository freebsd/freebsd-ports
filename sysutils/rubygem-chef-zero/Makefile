PORTNAME=	chef-zero
PORTVERSION=	15.0.21
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server
WWW=		https://github.com/chef/chef-zero

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport70>=7<8.1:devel/rubygem-activesupport70 \
		rubygem-ffi-yajl>=2.2<4.0:devel/rubygem-ffi-yajl \
		rubygem-hashie>=2.0<6.0:devel/rubygem-hashie \
		rubygem-mixlib-log>=2.0<4.0:devel/rubygem-mixlib-log \
		rubygem-rack>=3.1.16,3<4,3:www/rubygem-rack \
		rubygem-rackup>=2.2.1<3:www/rubygem-rackup \
		rubygem-unf_ext>=0.0.8<0.1:textproc/rubygem-unf_ext \
		rubygem-uuidtools>=2.1:devel/rubygem-uuidtools \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/chef-zero

.include <bsd.port.mk>
