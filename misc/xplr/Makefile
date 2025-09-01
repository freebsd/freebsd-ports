PORTNAME=	xplr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.9
PORTREVISION=	7
CATEGORIES=	misc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Hackable, minimal, fast TUI file explorer
WWW=		https://xplr.dev

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cargo compiler desktop-file-utils gmake luajit
USE_GITHUB=	yes
GH_ACCOUNT=	sayanarijit

BINARY_ALIAS=	make=gmake

PORTDOCS=	CODE_OF_CONDUCT.md README.md RELEASE.md
_EXAMPLES=	${WRKSRC}/src/init.lua
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES

_ASSETS=	${WRKSRC}/assets
_ICONS=		${STAGEDIR}${PREFIX}/share/icons/hicolor

post-install:
	${INSTALL_DATA} ${_ASSETS}/desktop/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

	@${MKDIR} ${_ICONS}/scalable/apps
	${INSTALL_DATA} ${_ASSETS}/icon/${PORTNAME}.svg \
		${_ICONS}/scalable/apps
.for res in 16 32 64 128
	@${MKDIR} ${_ICONS}/${res}x${res}/apps
.for icon in ico png
	${INSTALL_DATA} ${_ASSETS}/icon/${PORTNAME}${res}.${icon} \
		${_ICONS}/${res}x${res}/apps/${PORTNAME}.${icon}
.endfor
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_EXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
