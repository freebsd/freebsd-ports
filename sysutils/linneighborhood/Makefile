# New ports collection makefile for:    LinNeighborhood
# Please read files/porters-note!
# Date created:                         2003/04/06
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	LinNeighborhood
PORTVERSION=	0.6.5
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bnro.de/~schmidjo/download/

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	GTK+ gui for browsing and mounting SMB filesystems

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

post-patch:
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
