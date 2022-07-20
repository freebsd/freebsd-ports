PORTNAME=	guard-livereload
PORTVERSION=	2.5.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically reloads your browser when 'view' files are modified

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-em-websocket>=0.5<1:www/rubygem-em-websocket \
		rubygem-guard>=2.8<3:sysutils/rubygem-guard \
		rubygem-guard-compat>=1.0<2:sysutils/rubygem-guard-compat \
		rubygem-multi_json>=1.8<2:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
