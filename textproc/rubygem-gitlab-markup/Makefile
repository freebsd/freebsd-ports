PORTNAME=	gitlab-markup
PORTVERSION=	2.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Render any fancy GitLab markup
WWW=		https://gitlab.com/gitlab-org/gitlab-markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-creole>=0.5.0<0.6:textproc/rubygem-creole \
		rubygem-org-ruby>=0.9<1:textproc/rubygem-org-ruby \
		rubygem-rdoc-gitlab>=6.13<7:devel/rubygem-rdoc-gitlab \
		rubygem-redcloth>=4.3<5:www/rubygem-redcloth \
		rubygem-wikicloth081>=0.8.1<0.8.2:textproc/rubygem-wikicloth081

USES=		gem python:run shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/gitlab-markup

SHEBANG_FILES=	lib/github/commands/rest2html \
		script/bootstrap \
		script/cibuild

.include <bsd.port.mk>
