# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ed2k-gtk-gui
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	ed2k-gtk-gui_${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GTK GUI to eDonkey2000 'core' command line client

LIB_DEPENDS=	gnet.1:${PORTSDIR}/net/gnet
RUN_DEPENDS=	donkey:${PORTSDIR}/net/linux-edonkey-core

USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

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
