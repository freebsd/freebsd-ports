PORTNAME=	mdp
PORTVERSION=	1.0.18
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line based markdown presentation tool
WWW=		https://github.com/visit1985/mdp

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake ncurses

MAKE_ARGS=	LDLIBS="${NCURSESLIBS}"

PLIST_FILES=	bin/mdp \
		share/man/man1/mdp.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	visit1985

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mdp.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
