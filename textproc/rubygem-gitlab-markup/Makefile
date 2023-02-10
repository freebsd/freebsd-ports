PORTNAME=	gitlab-markup
PORTVERSION=	1.8.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Render any fancy GitLab markup
WWW=		https://gitlab.com/gitlab-org/gitlab-markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem python:run shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/gitlab-markup

SHEBANG_FILES=	lib/github/commands/rest2html \
		script/bootstrap \
		script/cibuild

.include <bsd.port.mk>
