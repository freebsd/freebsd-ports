# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.6.1
PORTREVISION=	1
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
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes

DOCSDIR=	${PREFIX}/share/doc/ed2k_gui
.ifndef(NOPORTDOCS)
MAN1=		ed2k-gtk-gui.1 ed2k_gui.1
.endif

post-patch:
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's|^(SUBDIRS.*)docs|\1|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${LN} -s ed2k_gui ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.mk>
