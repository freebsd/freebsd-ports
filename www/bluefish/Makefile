# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	2.2.6
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/ \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libenchant.so:${PORTSDIR}/textproc/enchant \
		libgucharmap.so:${PORTSDIR}/deskutils/gucharmap

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

USES=		gmake pkgconfig desktop-file-utils shared-mime-info \
		tar:bzip2 libtool
USE_GNOME=	gnomeprefix gtk20 gnomevfs2 gnomemimedata
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk2 \
		--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps

OPTIONS_DEFINE=	DEBUG NLS TIDY WEBLINT DOCS

DEBUG_DESC=	Enable debugging output
TIDY_DESC=	Include Tidy HTML cleanup program
WEBLINT_DESC=	Include Weblint syntax and style checker

OPTIONS_DEFAULT=	WEBLINT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--with-debugging-output
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MTIDY}
RUN_DEPENDS+=	tidy4:${PORTSDIR}/www/tidy
.endif

.if ${PORT_OPTIONS:MWEBLINT}
RUN_DEPENDS+=	weblint:${PORTSDIR}/www/weblint
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/bflang
	${INSTALL_DATA} ${WRKSRC}/data/bflang/sample.bflang2 \
		${STAGEDIR}${DOCSDIR}/bflang
.endif
	(cd ${STAGEDIR}${PREFIX}/lib/bluefish/ && \
		${STRIP_CMD} *.so)

.include <bsd.port.post.mk>
