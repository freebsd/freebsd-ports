# $FreeBSD$

PORTNAME=	github-markup
PORTVERSION=	1.5.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Render any fancy markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rinku>=0:www/rubygem-rinku

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix

PLIST_FILES=	bin/github-markup

SHEBANG_FILES=	script/bootstrap \
		script/cibuild

.include <bsd.port.mk>
