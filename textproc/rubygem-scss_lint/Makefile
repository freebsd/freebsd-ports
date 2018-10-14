# $FreeBSD$

PORTNAME=	scss_lint
PORTVERSION=	0.57.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SCSS linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rake>=0.9:devel/rubygem-rake \
		rubygem-sass>=3.5.5:textproc/rubygem-sass

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/scss-lint

.include <bsd.port.mk>
