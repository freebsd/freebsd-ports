# New ports collection makefile for:   jpilot
# Version required:    0.93.1
# Date created:        23 August 1999
# Whom:                Alex Varju <varju@webct.com>
#
# $FreeBSD$
#

DISTNAME=	jpilot-0.93.1
CATEGORIES=	palm
MASTER_SITES=	http://jpilot.linuxbox.com/

MAINTAINER=	varju@webct.com

LIB_DEPENDS=	pisock:${PORTSDIR}/palm/pilot-link \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

PREFIX=		${LOCALBASE}/pilot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pilot-prefix=${PREFIX}

post-install:
	@strip ${PREFIX}/bin/jpilot

.include <bsd.port.mk>
