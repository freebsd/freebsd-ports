PORTNAME=	zsh-fast-syntax-highlighting
DISTVERSIONPREFIX=	v
DISTVERSION=	1.55
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	phantrungson17@gmail.com
COMMENT=	Optimized and extended zsh-syntax-highlighting
WWW=		https://github.com/zdharma-continuum/fast-syntax-highlighting

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	zsh>=5.4:shells/zsh

USE_GITHUB=	yes
GH_ACCOUNT=	zdharma-continuum
GH_PROJECT=	fast-syntax-highlighting

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} "! -path \./\.* ! -name *\.bak ! -name *\.orig"

.include <bsd.port.mk>
