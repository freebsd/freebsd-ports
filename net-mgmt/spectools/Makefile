# Created by: Henrik Brix Andersen <henrik@brixandersen.dk>
# $FreeBSD$

PORTNAME=	spectools
PORTVERSION=	201108.r1
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/ \
		LOCAL/brix
DISTNAME=	spectools-2011-08-R1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for the Wi-Spy spectrum analyzers from MetaGeek LLC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		gmake ncurses pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
ALL_TARGET=	spectool_net spectool_raw

PORTDOCS=	README

OPTIONS_DEFINE=	GTK2 NCURSES DOCS
OPTIONS_DEFAULT=	GTK2 NCURSES
OPTIONS_SUB=	yes

GTK2_ALL_TARGET=	spectool_gtk
GTK2_USE=		GNOME=gtk20
NCURSES_ALL_TARGET=	spectool_curses

post-patch:
# Provide the prototype for malloc(3)
	@${REINPLACE_CMD} -e '/<pthread\.h>/ \
		{ x; s/.*/#include <stdlib.h>/; G; }' \
			${WRKSRC}/ubertooth_hw_u1.c \
			${WRKSRC}/wispy_hw_24x.c \
			${WRKSRC}/wispy_hw_dbx.c \
			${WRKSRC}/wispy_hw_gen1.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_net ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_raw ${STAGEDIR}/${PREFIX}/bin

do-install-GTK2-on:
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_gtk ${STAGEDIR}/${PREFIX}/bin

do-install-NCURSES-on:
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_curses ${STAGEDIR}/${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
