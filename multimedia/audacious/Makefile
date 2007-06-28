# New ports collection makefile for:	audacious
# Date created:			2006-01-01
# Whom:				Zastupov Stepan [RedChrom] <redchrom@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	audacious
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://static.audacious-media-player.org/release/
MASTER_SITE_SUBDIR=oliver
EXTRACT_SUFX=.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A media player based on BMP and XMMS

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
USE_LDCONFIG=	yes
USE_XLIB=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

MAN1=		audacious.1 audtool.1

LIB_DEPENDS=	mcs.1:${PORTSDIR}/devel/libmcs

PORTDOCS=	README AUTHORS ChangeLog NEWS

OPTIONS=	CHARSET	"Build with automatic charset detection" off \
		GNOME	"Build with gconf support" off \
		NLS	"Native Language Support" on \
		XML	"Build with xml support" on

.include <bsd.port.pre.mk>

.if defined(WITH_CHARSET_DETECTION)
CONFIGURE_ARGS+=--enable-chardet
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gconf2
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

.if !defined(WITHOUT_XML)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.else
CONFIGURE_ARGS+=--with-xml-prefix=/
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(LIBDIR)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|datarootdir}/man|prefix}/man|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-c |--check-format --check-domain |g' \
		${WRKSRC}/po/Makefile.in.in

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
