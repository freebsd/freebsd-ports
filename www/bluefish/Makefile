# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#   $MCom: ports-stable/www/bluefish/Makefile,v 1.2 2005/08/21 20:03:36 kwm Exp $
#

PORTNAME=	bluefish
PORTVERSION=	1.0.5
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.wur.nl/~olivier/${DOWNLOAD}/ \
		http://bluefish.mrball.net/${DOWNLOAD}/ \
		ftp://ftp.ratisbona.com/pub/bluefish/${DOWNLOAD}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre-utf8 \
		aspell.16:${PORTSDIR}/textproc/aspell

.if !defined(WITHOUT_WEBLINT)
RUN_DEPENDS+=	weblint:${PORTSDIR}/www/weblint
.endif
.if defined(WITH_TIDY)
RUN_DEPENDS+=	tidy:${PORTSDIR}/www/tidy
.endif

DOWNLOAD=	downloads
USE_BZIP2=	yes
USE_GNOME=	gnomehier gtk20 gnomevfs2
WANT_GNOME=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-freedesktop_org-menu=${PREFIX}/share/gnome/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--without-gnome2_4-mime \
		--without-gnome2_4-appreg \
		--with-icon-path=${PREFIX}/share/gnome/pixmaps

# Turns debugging output on
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debugging-output
.endif

.if defined(WITHOUT_SPLASH)
CONFIGURE_ARGS+=	--disable-splash-screen
.endif

MAN1=		bluefish.1

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

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

.include <bsd.port.post.mk>
