# New ports collection makefile for:   jpilot
# Version required:    0.95
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#
# "?=" and "+=" are for including this Makefile from japanese/jpilot

DISTNAME=	jpilot-0.95
CATEGORIES=	palm comms
MASTER_SITES=	http://jpilot.linuxbox.com/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-1-datebook-0.95 \
		patch-1-todo-0.95 \
		patch-1-todo_gui-0.95

MAINTAINER?=	varju@webct.com

LIB_DEPENDS=	pisock.3:${PORTSDIR}/palm/pilot-link \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

PREFIX=		${LOCALBASE}/pilot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pilot-prefix=${PREFIX}
CONFIGURE_ENV+=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

post-install:
	@strip ${PREFIX}/bin/jpilot

.include <bsd.port.mk>
