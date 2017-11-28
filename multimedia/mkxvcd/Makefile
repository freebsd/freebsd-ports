# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	mkxvcd
PORTVERSION=	2.0.2
PORTREVISION=	12
CATEGORIES=	multimedia
MASTER_SITES=	SF/kvcd4nix/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes high quality X/K/S/VCD movies from many formats

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	mpeg2enc:multimedia/mjpegtools \
		bash:shells/bash \
		mplayer:multimedia/mplayer \
		transcode:multimedia/transcode

USES=		shebangfix
SHEBANG_FILES=	${PORTNAME}.sh
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS Changelog README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
