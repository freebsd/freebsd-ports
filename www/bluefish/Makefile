# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	2.2.7
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/ \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libenchant.so:${PORTSDIR}/textproc/enchant

USES=		gmake pkgconfig desktop-file-utils shared-mime-info \
		tar:bzip2 libtool
USE_GNOME=	gnomeprefix gtk20 gnomevfs2 gnomemimedata intltool
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk2 \
		--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG NLS TIDY WEBLINT EXAMPLES
OPTIONS_DEFAULT=WEBLINT
OPTIONS_SUB=	yes

DEBUG_DESC=	Enable debugging output
TIDY_DESC=	Include Tidy HTML cleanup program
WEBLINT_DESC=	Include Weblint syntax and style checker

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES_OFF=		gettext-tools

DEBUG_CONFIGURE_ON=	--with-debugging-output
LIBGNOME_USE=		GNOME=libgnomeui
TIDY_RUN_DEPENDS=	tidy4:${PORTSDIR}/www/tidy
WEBLINT_RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

post-patch:
	@${REINPLACE_CMD} -e '/^bflangsampledir = /s|$$(docdir)/bflang|${EXAMPLESDIR}|' \
		${WRKSRC}/data/bflang/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime

.include <bsd.port.mk>
