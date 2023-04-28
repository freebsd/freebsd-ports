PORTNAME=	imgurbash2
DISTVERSION=	3.3
CATEGORIES=	sysutils

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Upload or delete images and videos to imgur
WWW=		https://github.com/ram-on/imgurbash2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash>0:shells/bash \
		curl>0:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	ram-on

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR}/examples.md

OPTIONS_RADIO=			CLIPBOARD
OPTIONS_RADIO_CLIPBOARD=	WL_COPY XCLIP XSEL

WL_COPY_DESC=	Use wl-copy
XCLIP_DESC=	Use xclip
XSEL_DESC=	Use xsel-conrad

WL_COPY_RUN_DEPENDS=	wl-clipboard>0:x11/wl-clipboard
XCLIP_RUN_DEPENDS=	xclip>0:x11/xclip
XSEL_RUN_DEPENDS=	xsel-conrad>0:x11/xsel-conrad

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
