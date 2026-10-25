PORTNAME=	hyfetch
DISTVERSION=	2.1.0
CATEGORIES=	sysutils

MAINTAINER=	Drugmaster1464@outlook.com
COMMENT=	Neofetch-like system info tool with pride flag colors
WWW=		https://github.com/hykilpikonna/hyfetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	hykilpikonna

SHEBANG_FILES=	neofetch

CARGO_CARGOTOML=	${WRKSRC}/crates/${PORTNAME}/Cargo.toml
CARGO_INSTALL_PATH=	crates/${PORTNAME}

CONFLICTS_INSTALL=	neofetch

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/neofetch ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
