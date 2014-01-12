# Created by: Henrik Brix Andersen <henrik@brixandersen.dk>
# $FreeBSD$

PORTNAME=	spectools
PORTVERSION=	201108.r1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix
DISTNAME=	spectools-2011-08-R1

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Tools for the Wi-Spy spectrum analyzers from MetaGeek LLC

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		gmake pkgconfig

PORTDOCS=	README

OPTIONS_DEFINE=	GTK2 NCURSES
OPTIONS_DEFAULT=	GTK2 NCURSES

ALL_TARGET=	spectool_net spectool_raw

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
ALL_TARGET+=	spectool_gtk
LIB_DEPENDS+=	gtk:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if ${PORT_OPTIONS:MNCURSES}
ALL_TARGET+=	spectool_curses
PLIST_SUB+=	NCURSES=""
.else
PLIST_SUB+=	NCURSES="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not build: duplicate definition of malloc
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_net ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_raw ${STAGEDIR}/${PREFIX}/bin
.if ${PORT_OPTIONS:MGTK2}
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_gtk ${STAGEDIR}/${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MNCURSES}
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_curses ${STAGEDIR}/${PREFIX}/bin
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}/${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
