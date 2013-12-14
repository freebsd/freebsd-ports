# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/avahi-gtk/Makefile,v 1.9 2012/07/09 18:22:19 kwm Exp $

PORTREVISION=	1
CATEGORIES=	net
PKGNAMESUFFIX=	-gtk

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ tools and bindings to the Avahi mDNS system

LIB_DEPENDS=	libavahi-common.so:${PORTSDIR}/net/avahi-app
RUN_DEPENDS=	avahi-header>=0.6:${PORTSDIR}/net/avahi-header

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	gtk
AVAHI_PKGCONFIG=avahi-ui.pc

MANPAGES=	bssh.1

USE_GNOME+=	libglade2

post-build:
	@(cd ${WRKSRC}/avahi-discover-standalone; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@(cd ${WRKSRC}/avahi-discover-standalone; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	${LN} -sf man/man1/bssh.1 ${STAGEDIR}${PREFIX}/man/man1/bvnc.1
	${LN} -sf man/man1/bssh.1 ${STAGEDIR}${PREFIX}/man/man1/bshell.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libavahi-ui.so.0

.include "${MASTERDIR}/Makefile"
