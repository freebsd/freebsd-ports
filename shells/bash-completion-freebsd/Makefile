PORTNAME=	bash-completion-freebsd
DISTVERSION=	1.5.0
CATEGORIES=	shells

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	FreeBSD-oriented extension to the Bash completion library
WWW=		https://github.com/0mp/bash-completion-freebsd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	0mp

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	etc/bash_completion.d/make \
		etc/bash_completion.d/mandoc \
		etc/bash_completion.d/pkg \
		etc/bash_completion.d/service

.include <bsd.port.mk>
