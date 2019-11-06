# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wmScoreBoard
PORTVERSION=	0.30
PORTREVISION=	4
CATEGORIES=	misc windowmaker
MASTER_SITES=	LOCAL/pat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dockapp that display game scores from excite

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../COPYING

RUN_DEPENDS=	wget:ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USES=		gmake shebangfix xorg
USE_XORG=	xpm x11 xext
SHEBANG_FILES=	GrabScores.excite

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmScoreBoard ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/GrabScores.excite ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in BUGS CHANGES HINTS README
	${INSTALL_DATA} ${WRKSRC}/../${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
