# New ports collection makefile for:   jpilot
# Version required:    0.98
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

DISTNAME=	jpilot-0.98
CATEGORIES=	palm comms
MASTER_SITES=	http://jpilot.linuxbox.com/

MAINTAINER?=	varju@webct.com

LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		intl.1:${PORTSDIR}/devel/gettext

PREFIX=		${LOCALBASE}/pilot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pilot-prefix=${PREFIX}
CONFIGURE_ENV+=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpilot
	${CP} ${WRKSRC}/docs/plugin.html ${PREFIX}/share/doc/jpilot
.endif

.include <bsd.port.mk>
