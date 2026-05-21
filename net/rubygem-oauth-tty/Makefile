PORTNAME=	oauth-tty
PORTVERSION=	1.0.7
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 1.0 TTY Command Line Interface
WWW=		https://oauth-tty.galtzo.com/ \
		https://github.com/ruby-oauth/oauth-tty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-auth-sanitizer>=0.1<1:security/rubygem-auth-sanitizer \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-version_gem>=1.1.9<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/oauth

.include <bsd.port.mk>
