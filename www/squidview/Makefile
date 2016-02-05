# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squidview
PORTVERSION=	0.81
CATEGORIES=	www
MASTER_SITES=	http://www.rillion.net/squidview/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Monitor squid statistics in realtime

LICENSE=	GPLv2

USES=		ncurses
GNU_CONFIGURE=	yes

DOCS=		HOWTO README
DATAFILES=	aliases users words

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squidview ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATAFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/squidview.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
