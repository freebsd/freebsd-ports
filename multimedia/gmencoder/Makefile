# Ports collection makefile for:  gmencoder
# Date created:			  Wed Feb 25 03:20:50 EST 2004
# Whom:				  Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gmencoder
PORTVERSION=	0.1.0
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Gmencoder is Gnome2 front-end to mplayer/mencoder

BUILD_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder
RUN_DEPENDS=	mencoder:${PORTSDIR}/multimedia/mencoder

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui

MAN1=		gmencoder.1

DESKTOP_ENTRIES=	"Gmencoder" "Gnome2 front-end to mplayer/mencoder" \
		"" "gmencoder" "GNOME;Application;AudioVideo;" false

.include <bsd.port.pre.mk>

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O4||; s|type -path|which|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/main.c ${WRKSRC}/src/interface.c
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/^ALL_LINGUAS/d' ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${INSTALL_MAN}	${WRKSRC}/man/gmencoder.1 ${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
