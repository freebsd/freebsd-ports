PORTNAME=	zsh-you-should-use
DISTVERSION=	1.7.3
CATEGORIES=	shells

MAINTAINER=	phantrungson17@gmail.com
COMMENT=	ZSH plugin reminding you to use aliases for commands you typed
WWW=		https://github.com/MichaelAquilina/zsh-you-should-use

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zsh>=4.3:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	MichaelAquilina

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	${DATADIR}/you-should-use.plugin.zsh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/you-should-use.plugin.zsh ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
