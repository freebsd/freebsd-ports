# ex:ts=8
# New ports collection makefile for:	surf
# Date created:			Apr 23, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	surf
PORTVERSION=	1.0.5
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF

USE_XORG=	x11 xmu
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualize some real algebraic geometry

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gmp.8:${PORTSDIR}/math/libgmp4

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	surf.1

.if !defined(NOPORTDOCS)
PORTDOCS=	manual.sgml
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
