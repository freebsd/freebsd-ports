# New ports collection makefile for:	wispy-tools
# Date created:				13 Dec 2006
# Whom:					Henrik Brix Andersen <henrik@brixandersen.dk>
#
# $FreeBSD$
#

PORTNAME=	wispy-tools
PORTVERSION=	200609.r1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.kismetwireless.net/code/
DISTNAME=	wispy-tools-2006-09-R1

MAINTAINER=	henrik@brixandersen.dk
COMMENT=	Tools for the 2.4GHz Wi-Spy spectrum analyzer from MetaGeek LLC

LIB_DEPENDS=	usb-0.1:${PORTSDIR}/devel/libusb

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

PORTDOCS=	README

OPTIONS=	GTK "Enable graphical client" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602101
IGNORE=	is unsupported on systems prior to FreeBSD v602101
.elif ${OSVERSION} > 700000 && ${OSVERSION} < 700027
IGNORE=	is unsupported on systems prior to FreeBSD v700027
.endif

.if defined(WITH_GTK)
LIB_DEPENDS+=	gtk:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB=	WITH_GTK=""
.else
PLIST_SUB=	WITH_GTK="@comment "
.endif

do-build:
	cd ${WRKSRC} && ${GMAKE} wispy_curses wispy_log wispy_raw
.if defined(WITH_GTK)
	cd ${WRKSRC} && ${GMAKE} wispy_gtk
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wispy_curses ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wispy_log ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wispy_raw ${PREFIX}/bin
.if defined(WITH_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/wispy_gtk ${PREFIX}/bin
.endif

post-install:
.ifndef(NOPORTDOC)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
