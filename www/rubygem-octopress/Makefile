# $FreeBSD$

PORTNAME=	octopress
PORTVERSION=	3.0.11
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Static blogging framework leveraging Jekyll

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-jekyll3>=2.0:www/rubygem-jekyll3 \
		rubygem-mercenary>=0.3.2<0.4:devel/rubygem-mercenary \
		rubygem-octopress-deploy>=0:net/rubygem-octopress-deploy \
		rubygem-octopress-escape-code>=2.0<3:textproc/rubygem-octopress-escape-code \
		rubygem-octopress-hooks>=2.0<3:devel/rubygem-octopress-hooks \
		rubygem-redcarpet>=3.0<4:textproc/rubygem-redcarpet \
		rubygem-titlecase>=0:devel/rubygem-titlecase

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/octopress

.include <bsd.port.mk>
