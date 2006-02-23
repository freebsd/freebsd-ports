# New ports collection makefile for:	KPopup
# Date created:				Apr 4, 2003
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#
# $Tecnik: ports/net-im/kpopup/Makefile,v 1.8 2006/01/30 14:17:07 itetcu Exp $
#

PORTNAME=	kpopup
PORTVERSION=	0.9.8.2
CATEGORIES=	net-im kde
MASTER_SITES=	http://www.henschelsoft.de/kpopup/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	KDE program for sending and receiving MS Windows WinPopup messages

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba3

SUB_FILES=	pkg-message

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=

KPOPUP_DIR=	/var/tmp/kpopup

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/src/make_popup.cpp
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/admin/ltmain.sh
	@${REINPLACE_CMD} "s^/usr/bin^${LOCALBASE}/bin^; s^/var/lib/kpopup^${KPOPUP_DIR}^" \
		${WRKSRC}/src/misc.h

post-install:
	@${MKDIR} ${KPOPUP_DIR} && ${CHMOD} 777 ${KPOPUP_DIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
