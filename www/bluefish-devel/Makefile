# Created by: Sylvio Cesar Teixeira <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	1.3.7
PORTREVISION=	5
CATEGORIES=	www editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unstable/${PORTVERSION}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-unstable-${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Development release of port bluefish

LIB_DEPENDS=	pcre.3:${PORTSDIR}/devel/pcre \
		aspell.16:${PORTSDIR}/textproc/aspell

IGNORE=		the devel release are currently suspended, install www/bluefish, new release is 2.0

INSTALLS_ICONS=	yes

DATADIR=	share/${PORTNAME}-unstable

USES=		gmake tar:bzip2
USE_GNOME=	gnomeprefix gtk20 gnomevfs2 gnomemimedata desktopfileutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--without-gnome2_4-mime \
		--without-gnome2_4-appreg \
		--with-icon-path=${PREFIX}/share/pixmaps

NO_STAGE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if !defined(WITHOUT_WEBLINT)
RUN_DEPENDS+=	weblint:${PORTSDIR}/www/weblint
.endif
.if defined(WITH_TIDY)
RUN_DEPENDS+=	tidy:${PORTSDIR}/www/tidy
.endif

# Turns debugging output on
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debugging-output
.endif

.if defined(WITHOUT_SPLASH)
CONFIGURE_ARGS+=	--disable-splash-screen
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=			gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

MAN1=		bluefish-unstable.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Bluefish  has the following tunable option(s):"
	@${ECHO_MSG} "  WITH_DEBUG		for debug support"
	@${ECHO_MSG} "  WITHOUT_WEBLINT	disable the weblint syntax and style checker"
	@${ECHO_MSG} "  WITH_TIDY		for the tidy html cleanup program"
	@${ECHO_MSG} "  WITHOUT_SPLASH	disable the splash screen"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "For Highlighting to work, please enable UTF-8 support in devel/pcre."
	@${ECHO_MSG} "This will reduce the number of warning in the console when running bluefish."
	@${ECHO_MSG} ""

pre-install:
	@${MKDIR} ${PREFIX}/share/mime

.include <bsd.port.post.mk>
