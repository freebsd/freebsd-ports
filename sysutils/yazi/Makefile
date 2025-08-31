PORTNAME=	yazi
DISTVERSIONPREFIX=	v
DISTVERSION=	25.5.31
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Blazing fast terminal file manager
WWW=		https://yazi-rs.github.io/

LICENSE=	APACHE20 BSD2CLAUSE BSD3CLAUSE BSL ISCL MIT MPL20 \
		Unicode-DFS-2016 ZLIB
LICENSE_COMB=	multi
LICENSE_NAME_Unicode-DFS-2016=	Unicode License Agreement - Data Files and Software (2016)
LICENSE_TEXT_Unicode-DFS-2016=	Terms of use at https://spdx.org/licenses/Unicode-DFS-2016.html
LICENSE_PERMS_Unicode-DFS-2016=	dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

BUILD_DEPENDS=	gawk:lang/gawk \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libonig.so:devel/oniguruma
RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

USES=		cargo desktop-file-utils gmake
USE_GITHUB=	yes
GH_ACCOUNT=	sxyazi

CARGO_INSTALL_PATH=	yazi-fm yazi-cli

OPTIONS_DEFINE=		AUXTOOLS EXAMPLES
OPTIONS_DEFAULT=	AUXTOOLS

AUXTOOLS_DESC=		Install auxiliary tools (fd, fzf, etc.)
AUXTOOLS_RUN_DEPENDS=	7z:archivers/7-zip \
			chafa:graphics/chafa \
			fd:sysutils/fd \
			ffmpegthumbnailer:multimedia/ffmpegthumbnailer \
			fzf:textproc/fzf \
			jq:textproc/jq \
			nerd-fonts>=2.1.0:x11-fonts/nerd-fonts \
			pdfimages:graphics/poppler-utils \
			rg:textproc/ripgrep \
			zoxide:sysutils/zoxide

post-install:
	${INSTALL_DATA} ${WRKSRC}/assets/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop

post-install-EXAMPLES-on:
	(${MKDIR} ${STAGEDIR}${EXAMPLESDIR} && \
	cd ${WRKSRC}/yazi-config/preset && \
	${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
