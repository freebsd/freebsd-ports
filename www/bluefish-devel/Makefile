# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/${DOWNLOAD}/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.mrball.net/${DOWNLOAD}/ \
		ftp://ftp.ratisbona.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.shellhung.org/${DOWNLOAD}/

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		aspell.15:${PORTSDIR}/textproc/aspell

.if !defined(WITHOUT_WEBLINT)
RUN_DEPENDS+=	weblint:${PORTSDIR}/www/weblint
.endif
.if defined(WITH_TIDY)
RUN_DEPENDS+=	tidy:${PORTSDIR}/www/tidy
.endif

CONFLICTS=	bluefish-0.7*

DOWNLOAD=	downloads
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier gtk20 gnomevfs2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-gnome2-menu=${PREFIX}/share/gnome/apps/Applications \
		--with-icon-path=${PREFIX}/share/gnome/pixmaps

# Turns debugging output on
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debugging-output
.endif

.if defined(WITHOUT_SPLASH)
CONFIGURE_ARGS+=	--disable-splash-screen
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Bluefish  has the following tunable option(s):"
	@${ECHO_MSG} "  WITH_DEBUG		for debug support"
	@${ECHO_MSG} "  WITHOUT_WEBLINT	disable the weblint syntax and style checker"
	@${ECHO_MSG} "  WITH_TIDY		for the tidy html cleanup program"
	@${ECHO_MSG} "  WITHOUT_SPLASH	disable the splash screen"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
