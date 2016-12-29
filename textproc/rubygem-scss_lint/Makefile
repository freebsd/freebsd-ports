# $FreeBSD$

PORTNAME=	scss_lint
PORTVERSION=	0.51.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SCSS linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rake>=0.9:devel/rubygem-rake \
		rubygem-sass>=3.4.15:textproc/rubygem-sass

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/scss-lint

.include <bsd.port.mk>
