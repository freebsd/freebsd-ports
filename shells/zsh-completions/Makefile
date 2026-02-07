PORTNAME=	zsh-completions
PORTVERSION=	0.35.0
CATEGORIES=	shells

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Additional completion definitions for Zsh
WWW=		https://github.com/zsh-users/zsh-completions

LICENSE=	ZSH
LICENSE_NAME=	ZSH license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

NO_ARCH=	yes
NO_BUILD=	yes

GH_ACCOUNT=	zsh-users
USE_GITHUB=	yes

post-patch:
	@${RM} ${WRKSRC}/src/_tarsnap

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
