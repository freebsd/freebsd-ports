# New ports collection makefile for:	gnome-osd
# Date created:			21 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-osd
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://telecom.inescporto.pt/~gjc/gnome-osd/

MAINTAINER=	jylefort@brutele.be
COMMENT=	An On-Screen-Display infrastructure using Pango text rendering

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2
USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	gnome-osd.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|control-center-2.0/capplets|applications|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
