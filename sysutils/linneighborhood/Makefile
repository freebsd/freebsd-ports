# New ports collection makefile for:    LinNeighborhood
# Please read files/porters-note!
# Date created:                         2003/04/06
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	LinNeighborhood
PORTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bnro.de/~schmidjo/download/

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	GTK+ gui for browsing and mounting SMB filesystems

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

pre-configure:
	${CP} ${FILESDIR}/mntent* ${WRKSRC}/src

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
