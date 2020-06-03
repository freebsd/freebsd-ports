# $FreeBSD$

PORTNAME=	gitlab-markup
PORTVERSION=	1.7.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Render any fancy GitLab markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:run shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/gitlab-markup

SHEBANG_FILES=	lib/github/commands/rest2html \
		script/bootstrap \
		script/cibuild

.include <bsd.port.mk>
