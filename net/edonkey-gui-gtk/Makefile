# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.6.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ed2k-gtk-gui
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	ed2k-gtk-gui-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GTK GUI to eDonkey2000 'core' command line client

LIB_DEPENDS=	gnet-2.0:${PORTSDIR}/net/gnet2
RUN_DEPENDS=	donkey:${PORTSDIR}/net/linux-edonkey-core

USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE}

DOCSDIR=	${PREFIX}/share/doc/ed2k_gui
.ifndef(NOPORTDOCS)
MAN1=		ed2k-gtk-gui.1 ed2k_gui.1
.endif

post-patch:
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's|^(SUBDIRS.*)docs|\1|' \
		${WRKSRC}/Makefile.in
.endif
# fix build with GTK 2.4
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/ed2k_gui/Makefile.in

post-install:
	@${LN} -s ed2k_gui ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
