# New ports collection makefile for:   jpilot
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

PORTNAME=	jpilot
PORTVERSION=	0.99.4
CATEGORIES+=	palm comms
MASTER_SITES=	http://jpilot.org/

MAINTAINER?=	varju@webct.com

LIB_DEPENDS=	pisock.8:${PORTSDIR}/palm/pilot-link \
		intl.4:${PORTSDIR}/devel/gettext

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/jpilot/plugins
CONFIGURE_ARGS+=	--with-pilot-prefix=${PREFIX}
CFLAGS+=	-I${PREFIX}/include
CONFIGURE_ENV+= CPPFLAGS="-I${PREFIX}/include" LDFLAGS="-L${PREFIX}/lib"

MAN1=		jpilot-sync.1 jpilot.1 jpilot-dump.1

post-install:
	${MKDIR} ${PREFIX}/man/man1
	${CP} ${WRKSRC}/docs/jpilot-dump.1 ${PREFIX}/man/man1
	${CP} ${WRKSRC}/docs/jpilot-sync.1 ${PREFIX}/man/man1
	${CP} ${WRKSRC}/docs/jpilot.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon1.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon2.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon3.xpm ${PREFIX}/share/jpilot/icons
	${CP} ${WRKSRC}/icons/jpilot-icon4.xpm ${PREFIX}/share/jpilot/icons
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
