# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.4.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ed2k-gtk-gui
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	ed2k-gtk-gui_0.4.0-1

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	gnet.1:${PORTSDIR}/net/gnet
RUN_DEPENDS=	donkey:${PORTSDIR}/net/edonkey-core

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/ed2k_gui-0.4.0

post-patch:
# CFLAGS safeness
	@${REINPLACE_CMD} -E -e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's|^(SUBDIRS.*)docs|\1|' \
		${WRKSRC}/ed2k_gui/Makefile.in
.endif

post-install:
	@${LN} -s ed2k_gui ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
