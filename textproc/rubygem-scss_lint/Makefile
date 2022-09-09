PORTNAME=	scss_lint
PORTVERSION=	0.59.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SCSS linter
WWW=		https://github.com/sds/scss-lint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-sass>=3.5.5<4:textproc/rubygem-sass

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/scss-lint

.include <bsd.port.mk>
