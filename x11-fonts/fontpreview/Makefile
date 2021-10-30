PORTNAME=	fontpreview
DISTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	x11-fonts graphics

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Very customizable and minimal font previewer written in Bash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		fzf:textproc/fzf \
		getopt>0:misc/getopt \
		sxiv:graphics/sxiv \
		xdotool:x11/xdotool

USES=		magick:7,run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	sdushantha
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md extra/

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|%%GETOPT%%|${LOCALBASE}/bin/getopt|' \
		${WRKSRC}/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/extra
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/* ${STAGEDIR}${DOCSDIR}/extra

.include <bsd.port.mk>
