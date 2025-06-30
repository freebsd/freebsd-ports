PORTNAME=	rox-filer
PORTVERSION=	2.11
PORTREVISION=	14
CATEGORIES=	x11-fm gnome
MASTER_SITES=	SF/rox/rox/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple and easy to use graphical file manager
WWW=		https://rox.sourceforge.net/phpwiki/index.php/ROX-Filer

LICENSE=	GPLv2+

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinotify.so:devel/libinotify

PLIST_SUB+=	LOCALBASE=${LOCALBASE}

USES=		gettext-runtime:build gmake gnome pkgconfig shared-mime-info \
		tar:bzip2 xorg
USE_XORG=	ice sm x11 xaw xorgproto
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk20 libxml2 pango

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		APP_DIR=${WRKSRC}/ROX-Filer
CONFIGURE_ARGS=		--enable-rox --with-platform=FreeBSD
CONFIGURE_WRKSRC=	${WRKSRC}/ROX-Filer/src
BUILD_WRKSRC=		${CONFIGURE_WRKSRC}
ALL_TARGET=
LIBS+=			-lm

OPTIONS_DEFINE=		NLS

NLS_USES=		gettext-runtime:run

post-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
	   ${CONFIGURE_WRKSRC}/configure \
	   ${CONFIGURE_WRKSRC}/choices.c \
	   ${CONFIGURE_WRKSRC}/support.c \
	   ${CONFIGURE_WRKSRC}/type.c \
	   ${CONFIGURE_WRKSRC}/usericons.c \
	   ${CONFIGURE_WRKSRC}/xdgmime.c
	${TOUCH} ${CONFIGURE_WRKSRC}/config.status

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC}/ROX-Filer && ${CP} -r .DirIcon AppInfo.xml AppRun \
	   Help Messages Options.xml ROX ROX-Filer Templates.ui images \
	   style.css subclasses ${STAGEDIR}${PREFIX}/apps/ROX-Filer
	cd ${WRKSRC} && ${CP} -r Choices ${STAGEDIR}${PREFIX}/share/
	${CAT} ${FILESDIR}/rox | ${SED} -e "s|%%PREFIX%%|${PREFIX}|" > ${STAGEDIR}${PREFIX}/bin/rox
	${INSTALL_MAN} ${WRKSRC}/rox.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/rox.xml ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
