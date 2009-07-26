# New ports collection makefile for:	spectools
# Date created:				09 Oct 2007
# Whom:					Henrik Brix Andersen <henrik@brixandersen.dk>
#
# $FreeBSD$
#

PORTNAME=	spectools
PORTVERSION=	200906.r1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brix
DISTNAME=	spectools-2009-06-R1

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Tools for the Wi-Spy spectrum analyzers from MetaGeek LLC

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

PORTDOCS=	README

OPTIONS=	GTK "Enable graphical client" On \
		NCURSES "Enable ncurses client" On

ALL_TARGET=	spectool_net spectool_raw

.include <bsd.port.options.mk>

.if defined(WITH_GTK)
ALL_TARGET+=	spectool_gtk
LIB_DEPENDS+=	gtk:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_NCURSES)
ALL_TARGET+=	spectool_curses
PLIST_SUB+=	NCURSES=""
.else
PLIST_SUB+=	NCURSES="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602101
IGNORE=	is unsupported on systems prior to FreeBSD v602101
.elif ${OSVERSION} > 700000 && ${OSVERSION} < 700027
IGNORE=	is unsupported on systems prior to FreeBSD v700027
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_net ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_raw ${PREFIX}/bin
.if defined(WITH_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_gtk ${PREFIX}/bin
.endif
.if defined(WITH_NCURSES)
	${INSTALL_PROGRAM} ${WRKSRC}/spectool_curses ${PREFIX}/bin
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
