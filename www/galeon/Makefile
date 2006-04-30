# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/www/galeon/Makefile,v 1.7 2005/11/28 17:45:54 ahze Exp $
#

PORTNAME=	galeon
PORTVERSION=	2.0.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://osdn.dl.sourceforge.net/sourceforge/galeon/
MASTER_SITE_SUBDIR=	${PORTNAME:S/2$//}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 Web browser based on gecko (the Mozilla rendering engine)

USE_GECKO=	firefox mozilla seamonkey xulrunner
WRKSRC=		${WRKDIR}/${PORTNAME:S/2$//}-${PORTVERSION:S/a$//}
USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui desktopfileutils \
		gnomedesktop
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-nautilus-view=no \
		--with-mozilla=${GECKO}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		galeon.1
GCONF_SCHEMAS=	galeon.schemas

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

.if ${OSVERSION} > 500000
# Galeon does not build correctly in -CURRENT if -Werror is passed
# to the compiler.
NO_WERROR=	yes
.endif
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-werror
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${REINPLACE_CMD} -e 's|@prefix@/@DATADIRNAME@|@datadir@|g' \
		${WRKSRC}/ui/galeon-bookmarks-editor-ui.xml.in
	@${REINPLACE_CMD} -e 's|/usr/lib/mozilla/plugins|${X11BASE}/lib/browser_plugins:${X11BASE}/lib/browser_linux_plugins|' \
		${WRKSRC}/mozilla/mozilla-embed-shell.cpp

.include <bsd.port.post.mk>
