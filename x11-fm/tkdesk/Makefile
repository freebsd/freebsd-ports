# New ports collection makefile for:	tkdesk
# Date created:         30 Jul 1996
# Whom:                 shanee@rabbit.augusta.de
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11-fm tk83
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical, highly configurable and powerful file manager

LIB_DEPENDS=	itcl32:${PORTSDIR}/lang/itcl \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${LOCALBASE}/lib/tcl8.3
CONFIGURE_ARGS+=--with-tk=${LOCALBASE}/lib/tk8.3
CONFIGURE_ARGS+=--with-itcl=${LOCALBASE}/lib/itcl3.2

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

pre-install:
	@${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} ';'

post-install:
	${STRIP_CMD} ${PREFIX}/bin/tkdesksh
	${STRIP_CMD} ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
