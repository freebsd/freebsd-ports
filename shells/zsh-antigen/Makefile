PORTNAME=	zsh-antigen
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.3
CATEGORIES=	shells

MAINTAINER=	gudfitz@gmail.com
COMMENT=	Tool for managing Zshell plugins inspired by Vundle

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zsh>=4.3.11:shells/zsh \
		git:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	zsh-users
GH_PROJECT=	antigen

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${DATADIR}/antigen.zsh
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/antigen.zsh ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
