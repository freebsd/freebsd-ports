# $FreeBSD$

PORTNAME=	github-markup
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Render any fancy markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	script/bootstrap \
		script/cibuild

PLIST_FILES=	bin/github-markup

.include <bsd.port.mk>
