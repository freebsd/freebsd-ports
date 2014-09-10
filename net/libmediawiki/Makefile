# $FreeBSD$

PORTNAME=	libmediawiki
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
CATEGORIES=	net kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for accessing MediaWiki sites

.include "${.CURDIR}/../../graphics/digikam-kde4/Makefile.common"

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
