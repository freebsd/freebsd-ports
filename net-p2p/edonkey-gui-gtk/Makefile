# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-p2p/edonkey-gui-gtk/Makefile,v 1.2 2006/10/05 05:04:46 mezz Exp $
#

PORTNAME=	edonkey
PORTVERSION=	0.6.4
PORTREVISION=	7
CATEGORIES=	net-p2p
MASTER_SITES=	SF/ed2k-gtk-gui/ed2k-gtk-gui/${PORTVERSION}
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	ed2k-gtk-gui-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK GUI to eDonkey2000 'core' command line client

LIB_DEPENDS=	gnet-2.0:${PORTSDIR}/net/gnet2
RUN_DEPENDS=	donkey:${PORTSDIR}/net-p2p/linux-edonkey-core

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ed2k-gtk-gui.1 ed2k_gui.1

DOCSDIR=	${PREFIX}/share/doc/ed2k_gui
DATADIR=	${PREFIX}/share/ed2k_gui

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^SUBDIRS =.*$$|SUBDIRS =|g' \
		 ${WRKSRC}/docs/Makefile.in
	@${REINPLACE_CMD} -e 's|-Wall -g||g ; \
		 s| == "xyes| = "xyes|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DG.*_DISABLE_DEPRECATED||g'

post-install:
	@${LN} -sf ed2k_gui ${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/en/index* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/deutsch
	${INSTALL_DATA} ${WRKSRC}/docs/de/index* ${DOCSDIR}/deutsch
	@${MKDIR} ${DOCSDIR}/espanol
	${INSTALL_DATA} ${WRKSRC}/docs/es/index* ${DOCSDIR}/espanol
	@${MKDIR} ${DOCSDIR}/francais
	${INSTALL_DATA} ${WRKSRC}/docs/fr/index* ${DOCSDIR}/francais
	@${MKDIR} ${DOCSDIR}/pl
	${INSTALL_DATA} ${WRKSRC}/docs/pl/index* ${DOCSDIR}/pl
.endif

.include <bsd.port.mk>
