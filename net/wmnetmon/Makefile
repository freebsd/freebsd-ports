# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	wmnetmon
PORTVERSION=	0.2p5
PORTREVISION=	2
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.linuks.mine.nu/dockapps/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A host availability monitor intended for the WindowMaker dock

USE_XORG=	xpm
GNU_CONFIGURE=	yes

BINMODE=	4755

PLIST_FILES=	bin/wmnetmon share/examples/wmnetmon/wmnetmonrc
PLIST_DIRS=	share/examples/wmnetmon

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmnetmon ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wmnetmonrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
