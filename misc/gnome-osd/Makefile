# New ports collection makefile for:	gnome-osd
# Date created:			21 Aug 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-osd
PORTVERSION=	0.20.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://launchpadlibrarian.net/63944370/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An On-Screen-Display infrastructure using Pango text rendering

USE_GNOME=	gnomehack gnomeprefix intlhack pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

GCONF_SCHEMAS=	gnome-osd.schemas

MAN1=		gnome-osd-client.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
