# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	mkxvcd
PORTVERSION=	2.0.2
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	SF/kvcd4nix/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Makes high quality X/K/S/VCD movies from many formats

LICENSE=	GPLv2

RUN_DEPENDS=	mpeg2enc:multimedia/mjpegtools \
		bash:shells/bash \
		mplayer:multimedia/mplayer \
		transcode:multimedia/transcode

USES=		shebangfix
SHEBANG_FILES=	${PORTNAME}.sh
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	AUTHORS Changelog README
OPTIONS_DEFINE=	DOCS

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
