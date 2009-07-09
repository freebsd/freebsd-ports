# New ports collection makefile for:   jpilot
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

PORTNAME=	jpilot
PORTVERSION=	1.6.2
CATEGORIES+=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://jpilot.org/

MAINTAINER?=	samm@os2.kiev.ua
COMMENT=	Desktop Organizer Software for the Palm Pilot

LIB_DEPENDS=	pisock.9:${PORTSDIR}/palm/pilot-link

USE_GMAKE=	yes
USE_GNOME=	gnomehier
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/jpilot/plugins

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

USE_GNOME+=	gtk20

MAN1=		jpilot-dial.1 jpilot-dump.1 jpilot-sync.1 jpilot.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-build:
	cd ${WRKSRC}/docs && ${GMAKE}
post-install:
	@${FIND} ${PREFIX}/lib/jpilot ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/jpilot -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dial.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/docs/jpilot-dump.1 ${PREFIX}/man/man1
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
.for i in AUTHORS BUGS COPYING ChangeLog INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/icons/README ${DOCSDIR}/README.icons
.endif

.include <bsd.port.mk>
