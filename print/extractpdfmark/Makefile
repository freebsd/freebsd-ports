PORTNAME=	extractpdfmark
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	print

MAINTAINER=	m.ne@gmx.net
COMMENT=	Extract page mode and named destinations as PDFmark from PDF
WWW=		https://github.com/trueroad/extractpdfmark/

LICENSE=	GPLv3+

LIB_DEPENDS=	libpoppler-cpp.so:graphics/poppler

USES=		autoreconf gettext-tools pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	trueroad

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-poppler=cpp

post-patch:
	@${TOUCH} ${WRKSRC}/config.rpath

.include <bsd.port.mk>
