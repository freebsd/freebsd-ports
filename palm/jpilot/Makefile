# New ports collection makefile for:   jpilot
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

PORTNAME=	jpilot
PORTVERSION=	0.99.7
PORTREVISION=	3
CATEGORIES+=	palm comms
MASTER_SITES=	http://jpilot.org/

MAINTAINER?=	freebsd-ports@varju.ca
COMMENT=	Desktop Organizer Software for the Palm Pilot

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier
USE_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/jpilot/plugins
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.if defined(WITH_GTK1)
USE_GNOME+=	gtk12
.else
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk2=yes
.endif

MAN1=		jpilot-sync.1 jpilot.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
	@${FIND} ${PREFIX}/lib/jpilot ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/jpilot -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-sync.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot.1 ${PREFIX}/man/man1
	@${MKDIR} ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${DATADIR}/icons
	${INSTALL_DATA} ${WRKSRC}/empty/*.pdb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jpilotrc.* ${DATADIR}
	@${FIND} ${DATADIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in html png jpg
	${INSTALL_DATA} ${WRKSRC}/docs/*.${ext} ${DOCSDIR}
.endfor
.for i in AUTHORS BUGS COPYING ChangeLog INSTALL README TODO UPGRADING
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/README ${DOCSDIR}/README.icons
.endif

.include <bsd.port.mk>
