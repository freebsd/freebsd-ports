# ex:ts=8
# Ports collection makefile for:    xvnkb
# Date created:         Mon Apr 05, 2004
# Whom:                 Nguyen Tam Chinh (chinhngt@sectorb.msk.ru)
#
# $FreeBSD$
#

PORTNAME=	xvnkb
PORTVERSION=	0.2.9
PORTREVISION=	6
CATEGORIES=	vietnamese
MASTER_SITES=	SF

MAINTAINER=	chinhngt@sectorb.msk.ru
COMMENT=	A Vietnamese input method for X-Window

USE_GNOME=	gtk20

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}" XLIB_DIR="${LOCALBASE}"

.if defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--no-xft
.else
USE_XORG=	xft
.endif

SUB_LIST=	PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/xvnkb lib/libxvnkb.so lib/libxvnkb.so.0 lib/xvnkb.so.0.2.9

MAN1=		xvnkb.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' ${WRKSRC}/tools/Makefile.dep

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/xvnkb
	${INSTALL_MAN} ${FILESDIR}/xvnkb.1 ${MANPREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
