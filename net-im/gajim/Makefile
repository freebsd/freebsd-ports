# New ports collection makefile for:	gajim
# Date created:				27 April 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	gajim
PORTVERSION=	0.11
CATEGORIES=	net-im
MASTER_SITES=	http://www.gajim.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Jabber client based on a plugin system

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite21 \
		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GNOME=	gnometarget intlhack pygtk2
USE_PYTHON=	2.4+
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

MAN1=		gajim.1 \
		gajim-remote.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-remote
PLIST_SUB+=	DBUS="@comment "
.else
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
PLIST_SUB+=	DBUS=""
.endif

.if defined(WITHOUT_GTKSPELL)
CONFIGURE_ARGS+=	--disable-gtkspell
PLIST_SUB+=	GTKSPELL="@comment "
.else
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
PLIST_SUB+=	GTKSPELL=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|: install-docfilesDATA|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|^#!.*|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/scripts/gajim.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README README.html THANKS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
