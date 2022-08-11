PORTNAME=	license_scout
PORTVERSION=	2.6.7
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Discover license files of a project's dependencies

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-ffi-yajl>=2.2<3:devel/rubygem-ffi-yajl \
		rubygem-fuzzy_match>=0:devel/rubygem-fuzzy_match \
		rubygem-licensee>=9.8<10:devel/rubygem-licensee \
		rubygem-mixlib-cli>=0:devel/rubygem-mixlib-cli \
		rubygem-mixlib-config>=3.0<4.0:devel/rubygem-mixlib-config \
		rubygem-mixlib-log>=0:devel/rubygem-mixlib-log \
		rubygem-mixlib-shellout>=2.2<4.0:devel/rubygem-mixlib-shellout \
		rubygem-terminal-table>=0:textproc/rubygem-terminal-table \
		rubygem-toml-rb>=1.0:www/rubygem-toml-rb

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/license_scout

.include <bsd.port.mk>
