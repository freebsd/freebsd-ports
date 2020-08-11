# $FreeBSD$

PORTNAME=	autojump
PORTVERSION=	22.5.3
DISTVERSIONPREFIX=	release-v
CATEGORIES=	sysutils

MAINTAINER=	michel@boaventura.dev
COMMENT=	Faster way to navigate your filesystem

LICENSE=	GPLv3+

USES=	python:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wting
USE_PYTHON=	concurrent autoplist
SHEBANG_FILES=	bin/autojump

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/autojump
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${CP} ${INSTALL_WRKSRC}/bin/autojump ${STAGEDIR}${PREFIX}/bin
	${CP} ${INSTALL_WRKSRC}/bin/*.py ${STAGEDIR}${PREFIX}/bin
	${CP} ${INSTALL_WRKSRC}/bin/autojump.bash ${STAGEDIR}${PREFIX}/share/autojump
	${CP} ${INSTALL_WRKSRC}/bin/autojump.zsh ${STAGEDIR}${PREFIX}/share/autojump
	${CP} ${INSTALL_WRKSRC}/bin/autojump.fish ${STAGEDIR}${PREFIX}/share/autojump
	${CP} ${INSTALL_WRKSRC}/bin/_j ${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
