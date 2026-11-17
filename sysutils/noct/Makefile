PORTNAME=	noct
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	sysutils

MAINTAINER=	hedningakjetil@gmail.com
COMMENT=	Terminal filesystem inspection tool and viewer
WWW=		https://github.com/ferusx/noct

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	ferusx

PLIST_FILES=	bin/noct \
		bin/nt \
		share/man/man1/noct.1.gz

PORTDATA=	*

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/release/noct \
		${STAGEDIR}${PREFIX}/bin/noct
	${RLN} ${STAGEDIR}${PREFIX}/bin/noct ${STAGEDIR}${PREFIX}/bin/nt
	${INSTALL_MAN} ${WRKSRC}/man/man1/noct.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	cd ${WRKSRC}/themes && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DATADIR} " -name *.toml "

.include <bsd.port.mk>
