PORTNAME=	sndy
DISTVERSION=	0.0.6
CATEGORIES=	sysutils audio tcl

MAINTAINER=	Clockwork6400@protonmail.com
COMMENT=	Sound Switcher
WWW=		https://github.com/Clockwork6400/sndy

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		shebangfix tcl tk

USE_GITHUB=	yes
GH_ACCOUNT=	Clockwork6400

SHEBANG_FILES=	sndy
tk_OLD_CMD+=	/usr/local/bin/wish8.6

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/sndy \
		share/applications/sndy.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sndy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sndy.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
