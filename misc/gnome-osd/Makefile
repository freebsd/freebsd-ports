# New ports collection makefile for:	gnome-osd
# Date created:			21 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-osd
DISTVERSION=	0.9.1-1
CATEGORIES=	misc
MASTER_SITES=	http://telecom.inescporto.pt/~gjc/gnome-osd/${DISTVERSION:C|-.*$||}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	An On-Screen-Display infrastructure using Pango text rendering

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	gnome-osd.schemas
PORTDOCS=	AUTHORS NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|control-center-2.0/capplets|applications|; \
		s|$$(datadir)/dbus-1|$$(prefix)/share/dbus-1|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
