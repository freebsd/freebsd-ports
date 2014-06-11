# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	2.2.3
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/ \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		enchant.1:${PORTSDIR}/textproc/enchant \
		gucharmap.7:${PORTSDIR}/deskutils/gucharmap

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gtk20 gnomevfs2 gnomemimedata desktopfileutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk2 \
		--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps

MAN1=		bluefish.1

OPTIONS_DEFINE=	DEBUG TIDY WEBLINT

DEBUG_DESC=	Enable debugging output
TIDY_DESC=	Include Tidy HTML cleanup program
WEBLINT_DESC=	Include Weblint syntax and style checker

OPTIONS_DEFAULT=	WEBLINT

NO_STAGE=	yes
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
	@${MKDIR} ${PREFIX}/share/mime

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/bflang
	${INSTALL_DATA} ${WRKSRC}/data/bflang/sample.bflang2 ${DOCSDIR}/bflang
.endif

.include <bsd.port.post.mk>
