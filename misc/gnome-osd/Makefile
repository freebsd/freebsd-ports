# New ports collection makefile for:	gnome-osd
# Date created:			21 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		gnome-osd
PORTVERSION=		0.6.0
CATEGORIES=		misc
MASTER_SITES=		http://yang.inescn.pt/~gjc/gnome-osd/

MAINTAINER=		jylefort@brutele.be
COMMENT=		An On-Screen-Display infrastructure using Pango text rendering

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_GNOME=		gnomehack gnomeprefix intlhack pygnome2
USE_PYTHON=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's/^Icon=gnome-osd$$/&.png/' \
		${WRKSRC}/gnome-osd-properties.desktop.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} \
		${WRKSRC}/rbosd.py \
		${WRKSRC}/xchatosd.py \
		${EXAMPLESDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
