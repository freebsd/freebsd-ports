# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	merb-core
PORTVERSION=	1.1.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Merb. Pocket rocket web framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-erubis>=2.6.2:www/rubygem-erubis \
		rubygem-extlib>=0.9.13:devel/rubygem-extlib \
		rubygem-mime-types>=1.16:misc/rubygem-mime-types \
		rubygem-rack16>=0:www/rubygem-rack16 \
		rubygem-rake>=0:devel/rubygem-rake

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	spec10/public/webrat/test_app/gems/gems/erubis-2.6.2/bin/erubis \
		spec10/public/webrat/test_app/gems/gems/erubis-2.6.2/contrib/erubis

PLIST_FILES=	bin/merb

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s|/.*ruby|${ruby_CMD}|' \
		${WRKSRC}/spec10/public/core_ext/fixtures/gems/bin/edit_json.rb

.include <bsd.port.mk>
