# New ports collection makefile for:    crescendo
# Date created:         27.Apr 2000
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	crescendo
PORTVERSION=	1.1.6
CATEGORIES=	net gnome
MASTER_SITES=	http://crescendo.dpnd.com/files/

MAINTAINER=	dirk.meyer@dinoex.sub.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	tf:${PORTSDIR}/net/tinyfugue

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-compile-warnings=yes
CONFIGURE_ARGS+=	--localstatedir=${PREFIX}/share/gnome \
			--datadir=${PREFIX}/share/gnome \
			--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-g
PLIST_SUB=	DOCDIR=${DOCDIR}

DOCDIR=		share/doc/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
.for file in AUTHORS COPYING ChangeLog HACKING INSTALL NEWS \
		README README.BINARY TODO
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
