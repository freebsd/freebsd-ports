# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	wmnetmon
PORTVERSION=	0.2p5
PORTREVISION=	2
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.linuks.mine.nu/dockapps/

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Host availability monitor intended for the WindowMaker dock

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2020-05-05

USES=		xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

BINMODE=	4755

PLIST_FILES=	bin/wmnetmon share/examples/wmnetmon/wmnetmonrc

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmnetmon ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wmnetmonrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
