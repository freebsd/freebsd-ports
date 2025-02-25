PORTNAME=	vm-bhyve-zcomp
DISTVERSIONPREFIX=	v
DISTVERSION=	20250225.1
CATEGORIES=	sysutils

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Zsh completion for vm-bhyve
WWW=		https://github.com/metalefty/vm-bhyve-zcomp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zsh>=5.0:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	metalefty

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/zsh/site-functions/_vm

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/_vm ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
