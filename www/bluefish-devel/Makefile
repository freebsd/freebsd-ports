# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	bluefish
PORTVERSION=	0.11.20031031
CATEGORIES=	www editors
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/${DOWNLOAD}/ \
		ftp://bluefish.advancecreations.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.mrball.net/${DOWNLOAD}/ \
		ftp://ftp.ratisbona.com/pub/bluefish/${DOWNLOAD}/ \
		http://bluefish.shellhung.org/${DOWNLOAD}/
DISTNAME=	${PORTNAME}-2003-10-31

MAINTAINER=	einekoai@chello.nl
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		aspell.15:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	weblint:${PORTSDIR}/www/weblint

DOWNLOAD=	snapshots
WRKSRC=		${WRKDIR}/bluefish-gtk2
NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier gtk20
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

pre-everything::
.if !defined(WITH_DEBUG)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_DEBUG=yes for debug support"
.endif

.include <bsd.port.mk>
