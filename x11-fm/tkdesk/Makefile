# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	x11-fm tk83
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= X11/desktop

MAINTAINER=	spadger@best.com

LIB_DEPENDS=	itcl32:${PORTSDIR}/lang/itcl \
		BLT24.2:${PORTSDIR}/x11-toolkits/blt

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-tcl=${LOCALBASE}/lib/tcl8.3
CONFIGURE_ARGS+= --with-tk=${LOCALBASE}/lib/tk8.3
CONFIGURE_ARGS+= --with-itcl=${LOCALBASE}/lib/itcl3.2
CONFIGURE_ARGS+= --with-blt=${LOCALBASE}/lib

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

pre-install:
	@find ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} ';'

post-install:
	strip ${PREFIX}/bin/tkdesksh
	strip ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
