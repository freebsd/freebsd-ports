# New ports collection makefile for:   jpilot
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

PORTNAME=	jpilot
PORTVERSION=	0.99.6
PORTREVISION=	1
CATEGORIES+=	palm comms
MASTER_SITES=	http://jpilot.org/

MAINTAINER?=	varju@webct.com
COMMENT=	Desktop Organizer Software for the Palm Pilot

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link \
		intl.5:${PORTSDIR}/devel/gettext-old

CONFIGURE_ARGS+=	--with-pilot-prefix=${PREFIX}
.if defined(WITH_GTK2)
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--enable-gtk2=yes
.else
USE_GNOME=	gtk12
.endif

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/jpilot/plugins
CFLAGS+=	-I${PREFIX}/include
CONFIGURE_ENV+=	CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

MAN1=		jpilot-sync.1 jpilot.1

post-install:
	${MKDIR} ${PREFIX}/man/man1
	${CP} ${WRKSRC}/docs/jpilot-sync.1 ${PREFIX}/man/man1
	${CP} ${WRKSRC}/docs/jpilot.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon1.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon2.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon3.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon4.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/empty/AddressDB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/empty/DatebookDB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/empty/ExpenseDB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/empty/Memo32DB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/empty/MemoDB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/empty/ToDoDB.pdb ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/jpilotrc.blue ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/jpilotrc.default ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/jpilotrc.green ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/jpilotrc.purple ${PREFIX}/share/jpilot
	${CP} ${WRKSRC}/jpilotrc.steel ${PREFIX}/share/jpilot
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/manual.html ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/plugin.html ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/BUGS ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/COPYING ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/TODO ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/UPGRADING ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-address.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-datebook.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-expense.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-install.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-memo.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-prefs.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-print.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-search.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-todo.png ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/jpilot-toplogo.jpg ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/icons/README ${PREFIX}/share/doc/jpilot/README.icons
.endif

.include <bsd.port.mk>
