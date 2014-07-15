# Created by: Alex Varju <varju@webct.com>
# $FreeBSD$

# "?=" and "+=" are for including this Makefile from japanese/jpilot"

PORTNAME=	jpilot
PORTVERSION=	1.8.1
PORTREVISION=	2
CATEGORIES+=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://jpilot.org/

MAINTAINER?=	samm@os2.kiev.ua
COMMENT=	Desktop Organizer Software for the Palm Pilot

LICENSE=	GPLv2

LIB_DEPENDS=	libpisock.so:${PORTSDIR}/palm/pilot-link

USE_GCC=	any
USES=		pkgconfig gmake libtool
USE_GNOME=	gnomehier
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}
USE_GNOME+=	gtk20
OPTIONS_DEFINE=	DOCS NLS
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

post-build:
	cd ${WRKSRC}/docs && ${MAKE_CMD}

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dial.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dump.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-sync.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${STAGEDIR}${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/empty/*.pdb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jpilotrc.* ${STAGEDIR}${DATADIR}
.for ext in html png jpg
	${INSTALL_DATA} ${WRKSRC}/docs/*.${ext} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in AUTHORS BUGS COPYING ChangeLog INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/README ${STAGEDIR}${DOCSDIR}/README.icons

.include <bsd.port.mk>
