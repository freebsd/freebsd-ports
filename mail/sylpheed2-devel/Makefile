# New ports collection makefile for:	sylpheed
# Date created:                 15 June 2000
# Whom:                         shigeri <shigeri@m10.alpha-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	sylpheed
PORTVERSION=	0.3.18
CATEGORIES=	mail
MASTER_SITES=	http://www.kcn.ne.jp/~hiro-y/sylpheed/

MAINTAINER=	shigeri@m10.alpha-net.ne.jp

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS= --disable-glibtest --disable-gtktest

DOCS=		ABOUT-NLS COPYING ChangeLog ChangeLog.jp INSTALL INSTALL.jp \
		README README.jp TODO.jp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sylpheed
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/sylpheed
.endfor
.endif

.include <bsd.port.mk>
