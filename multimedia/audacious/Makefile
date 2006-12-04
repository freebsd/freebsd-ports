# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	1.2.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://audacious-media-player.org/release/
EXTRACT_SUFX=.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A media player based on BMP and XMMS

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_LDCONFIG=	yes
USE_XLIB=	yes

MAN1=		audacious.1 audtool.1

PORTDOCS=	README AUTHORS ChangeLog NEWS

OPTIONS=	GNOME	"Build with gconf support" off \
		NLS	"Native Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
USE_GNOME+=	gconf
CONFIGURE_ARGS+=--enable-gconf
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|intl \\|intl|; /-Wno-strict-aliasing/d' \
		${WRKSRC}/audacious/widgets/Makefile
.endif
	@${REINPLACE_CMD} -e 's|(LIBDIR)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_GNOME)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You have installed audacious with gconf support."
	@${ECHO_MSG} "ALL PRESETS will be stored in the gconf database."
	@${ECHO_MSG} ""
.endif
	

.include <bsd.port.post.mk>
