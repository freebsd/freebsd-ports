# New ports collection makefile for:	KPopup
# Date created:				Apr 4, 2003
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$

PORTNAME=	kpopup
PORTVERSION=	0.9.1
PORTREVISION=	3
CATEGORIES=	net kde
MASTER_SITES=	http://www.henschelsoft.de/kpopup/

MAINTAINER=	so14k@so14k.com
COMMENT=	KDE program for sending and receiving MS Windows WinPopup messages

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/kpopup/misc.cpp \
		${WRKSRC}/kpopup/make_popup.cpp ${WRKSRC}/kpopup/main.cpp
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${WRKSRC}/kpopup/misc.h

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},g'

.include <bsd.port.mk>
