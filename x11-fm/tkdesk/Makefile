# New ports collection makefile for:	tkdesk
# Version required:     1.0
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $Id: Makefile,v 1.11 1998/10/10 03:22:20 steve Exp $
#

DISTNAME=	tkdesk-1.1
CATEGORIES=	x11-fm tk42
MASTER_SITES=	http://people.mainz.netsurf.de/~bolik/tkdesk/

MAINTAINER=	dmlb@ragnet.demon.co.uk

LIB_DEPENDS=	tk42.1:${PORTSDIR}/x11-toolkits/tk42

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	TCLCONF_PATH=${LOCALBASE}/lib/tcl7.6
CONFIGURE_ENV+=	TKCONF_PATH=${LOCALBASE}/lib/tk4.2

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

post-install:
	strip ${PREFIX}/bin/tkdesksh
	strip ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
