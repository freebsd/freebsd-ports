# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	gnome-osd
PORTVERSION=	0.20.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://launchpadlibrarian.net/63944370/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	On-Screen-Display infrastructure using Pango text rendering

USES=		pathfix gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack pygnome2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

GCONF_SCHEMAS=	gnome-osd.schemas

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
