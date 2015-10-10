# $FreeBSD$

PORTNAME=	scss_lint
PORTVERSION=	0.42.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	SCSS linter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rainbow>=2.0:${PORTSDIR}/devel/rubygem-rainbow \
		rubygem-sass>=3.4.15:${PORTSDIR}/textproc/rubygem-sass

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/scss-lint

.include <bsd.port.mk>
