# New ports collection makefile for:	gnome-osd
# Date created:			21 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-osd
DISTVERSION=	0.11.3
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://telecom.inescporto.pt/~gjc/gnome-osd/${DISTVERSION:C|-.*$||}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An On-Screen-Display infrastructure using Pango text rendering

USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	gnome-osd.schemas
PORTDOCS=	AUTHORS NEWS README
MAN1=		gnome-osd-client.1

post-patch:
	@${REINPLACE_CMD} -e 's|control-center-2.0/capplets|applications|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
