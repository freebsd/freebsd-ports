# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	1.2
CATEGORIES=	x11-fm tk82
MASTER_SITES=	http://sd.znet.com/~jchris/tkdesk/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= X11/desktop

MAINTAINER=	andy@geek4food.org

LIB_DEPENDS=	itcl30.1:${PORTSDIR}/lang/itcl \
		BLT24.2:${PORTSDIR}/x11-toolkits/blt

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --with-tcl=${LOCALBASE}/lib/tcl8.2
CONFIGURE_ARGS+= --with-tk=${LOCALBASE}/lib/tk8.2
CONFIGURE_ARGS+= --with-itcl=${LOCALBASE}/lib/itcl3.0
CONFIGURE_ARGS+= --with-blt=${LOCALBASE}/lib

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

pre-install:
	@find ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} ';'

post-install:
	strip ${PREFIX}/bin/tkdesksh
	strip ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
