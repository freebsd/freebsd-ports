# New ports collection makefile for:   jpilot
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

PORTNAME=	jpilot
PORTVERSION=	0.99.2
PORTREVISION=	2
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

MAN1=		jpilot-sync.1 jpilot-upgrade-99.1 jpilot.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/manual.html ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/plugin.html ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/BUGS ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/COPYING ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/jpilot
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
