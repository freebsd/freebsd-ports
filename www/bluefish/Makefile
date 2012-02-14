# New ports collection makefile for:   bluefish
# Date created:			23 January 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#   $MCom: ports/www/bluefish/Makefile,v 1.6 2007/10/11 03:20:30 mezz Exp $
#

PORTNAME=	bluefish
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/ \
		SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LIB_DEPENDS=	pcre.1:${PORTSDIR}/devel/pcre \
		enchant.1:${PORTSDIR}/textproc/enchant \
		gucharmap.7:${PORTSDIR}/deskutils/gucharmap

INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
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

OPTIONS=	DEBUG "Enable debugging output" Off \
		TIDY "Include Tidy HTML cleanup program" Off \
		WEBLINT "Include Weblint syntax and style checker" On

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

# Turns debugging output on
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debugging-output
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if defined(WITH_TIDY)
RUN_DEPENDS+=	tidy:${PORTSDIR}/www/tidy
.endif
.if !defined(WITHOUT_WEBLINT)
RUN_DEPENDS+=	weblint:${PORTSDIR}/www/weblint
.endif

pre-install:
	@${MKDIR} ${PREFIX}/share/mime

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/bflang
	${INSTALL_DATA} ${WRKSRC}/data/bflang/sample.bflang2 ${DOCSDIR}/bflang
.endif

.include <bsd.port.post.mk>
