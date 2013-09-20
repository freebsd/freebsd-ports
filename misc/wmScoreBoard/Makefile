# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wmScoreBoard
PORTVERSION=	0.30
PORTREVISION=	4
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pat

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dockapp that display game scores from excite

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
USE_XORG=	xpm

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for docs in BUGS CHANGES HINTS README
	@${INSTALL_DATA} ${WRKSRC}/../${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
