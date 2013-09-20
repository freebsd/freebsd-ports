# Created by: Alex Varju <varju@webct.com>
# $FreeBSD$

# "?=" and "+=" are for including this Makefile from japanese/jpilot"

PORTNAME=	jpilot
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES+=	palm comms
MASTER_SITES=	http://www.mirrorservice.org/sites/master.us.finkmirrors.net/distfiles/ \
		http://jpilot.org/

MAINTAINER?=	samm@os2.kiev.ua
COMMENT=	Desktop Organizer Software for the Palm Pilot

LIB_DEPENDS=	pisock.9:${PORTSDIR}/palm/pilot-link

USE_GCC=	any
USES=		pkgconfig
USE_GMAKE=	yes
USE_GNOME=	gnomehier
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-pilot-prefix=${LOCALBASE}

LICENSE=	GPLv2

USE_GNOME+=	gtk20

MAN1=		jpilot-dial.1 jpilot-dump.1 jpilot-sync.1 jpilot.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
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
.if ${PORT_OPTIONS:MDOCS}
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
