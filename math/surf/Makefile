# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	surf
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visualize some real algebraic geometry

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		gmp.10:${PORTSDIR}/math/gmp

USE_XORG=	x11 xmu
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-cups --datadir=${PREFIX}/share

CONFLICTS=	surf-0* # www/surf

MAN1=		${PORTNAME}.1
PORTDOCS=	manual.sgml
PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/${PORTNAME}.xpm
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|@CUPS_TRUE@|#|g ; \
		 s|@CUPS_FALSE@||g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/docs/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
