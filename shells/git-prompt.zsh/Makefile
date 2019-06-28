# $FreeBSD$

PORTNAME=	git-prompt.zsh
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	shells

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Fast, customizable, pure-shell, asynchronous Git prompt for Zsh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zsh>=4.3:shells/zsh \
		git>=2.11.0:devel/git

USE_GITHUB=	yes
GH_ACCOUNT=	woefe

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${DATADIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
