# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.4.1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/

MAINTAINER=	shigeri@m10.alpha-net.ne.jp

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-glibtest --disable-gtktest --disable-imlibtest \
		--disable-compface --disable-gdk-pixbuf --enable-ipv6

PORTDOCS=	ChangeLog ChangeLog.jp INSTALL INSTALL.jp README README.jp \
		TODO.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sylpheed
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sylpheed
.endfor
.endif

.include <bsd.port.mk>
