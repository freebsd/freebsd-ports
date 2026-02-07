PORTNAME=	bat-extras
DISTVERSIONPREFIX=	v
DISTVERSION=	2024.08.24
CATEGORIES=	textproc

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Scripts that integrate with textproc/bat
WWW=		https://github.com/eth-p/bat-extras

LICENSE=	MIT

BUILD_DEPENDS=	bash:shells/bash \
		shfmt:devel/shfmt
RUN_DEPENDS=	bash:shells/bash \
		bat:textproc/bat

USE_GITHUB=	yes
GH_ACCOUNT=	eth-p
NO_ARCH=	yes

PLIST_FILES=	bin/batdiff \
		bin/batgrep \
		bin/batman \
		bin/batpipe \
		bin/batwatch \
		bin/prettybat
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-build:
	${WRKSRC}/build.sh --no-verify

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/batdiff   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/batgrep   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/batman    ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/batpipe   ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/batwatch  ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/prettybat ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
