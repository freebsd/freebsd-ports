# $FreeBSD$

PORTNAME=	scss_lint
PORTVERSION=	0.44.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SCSS linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rake>=10.0:${PORTSDIR}/devel/rubygem-rake \
		rubygem-sass>=3.4.15:${PORTSDIR}/textproc/rubygem-sass

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/scss-lint

.include <bsd.port.mk>
