# Created by: rea@FreeBSD.org
# $FreeBSD$

PORTNAME=	mu
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://mu0.googlecode.com/files/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Mail searching frontend for Xapian

LICENSE=	GPLv3

LIB_DEPENDS=	xapian:${PORTSDIR}/databases/xapian-core \
		gmime:${PORTSDIR}/mail/gmime24

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake
USE_GNOME=	glib20

MAN1=		mu-cfind.1 mu-easy.1 mu-extract.1 mu-find.1 mu-index.1 \
		mu-mkdir.1 mu-view.1 mu-add.1 mu-remove.1 mu-server.1 mu.1 \
		mug.1
MAN5=		mu-bookmarks.5

CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gui=none

do-install:
	cd ${WRKSRC}/mu && ${INSTALL_PROGRAM} mu ${PREFIX}/bin
	cd ${FILESDIR} && ${INSTALL_SCRIPT} mu-ask ${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5

.include <bsd.port.mk>
