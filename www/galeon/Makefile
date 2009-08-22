# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/www/galeon/Makefile,v 1.6 2008/11/16 20:00:21 marcus Exp $
#

PORTNAME=	galeon
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%202.x/Galeon%20${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME 2 Web browser based on gecko (the Mozilla rendering engine)

USE_GECKO=	firefox mozilla seamonkey xulrunner
WRKSRC=		${WRKDIR}/${PORTNAME:S/2$//}-${PORTVERSION:S/a$//}
USE_BZIP2=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui desktopfileutils \
		gnomedesktop
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-nautilus-view=no \
		--with-mozilla=${GECKO}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		galeon.1
GCONF_SCHEMAS=	galeon.schemas

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"

# Galeon does not build correctly in -CURRENT if -Werror is passed
# to the compiler.
NO_WERROR=	yes

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
	@${REINPLACE_CMD} -e 's|/usr/lib/mozilla/plugins|${LOCALBASE}/lib/browser_plugins/symlinks/gecko18|' \
		${WRKSRC}/mozilla/mozilla-embed-shell.cpp

.include <bsd.port.post.mk>
