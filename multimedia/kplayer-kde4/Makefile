# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kplayer
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Movie player based on mplayer

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

RUN_DEPENDS=	mplayer:multimedia/mplayer

USES=		cmake:insource gettext kde:4 qt:4 tar:bzip2
USE_QT=		corelib qmake_build moc_build rcc_build uic_build
USE_KDE=	kdelibs automoc4
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -L${LOCALBASE}/kde4/lib -lsolid

post-patch:
.for lang in da en es it pt sv
	${REINPLACE_CMD} -e "s,HTML_INSTALL_DIR},HTML_INSTALL_DIR}/${lang} SUBDIR kplayer,g" \
	 ${WRKSRC}/doc/${lang}/CMakeLists.txt
.endfor
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/*/index.docbook

.include <bsd.port.mk>
