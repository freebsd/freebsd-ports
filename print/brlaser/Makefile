# $FreeBSD$

PORTNAME=	brlaser
DISTVERSIONPREFIX=	v
DISTVERSION=	6
CATEGORIES=	print

MAINTAINER=	20.100@defert.com
COMMENT=	Brother laser printer driver

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups \
		libcupsimage.so:print/cups

USES=		cmake:insource,noninja

USE_GITHUB=	yes

GH_ACCOUNT=	pdewacht
GH_PROJECT=	brlaser

PLIST_FILES=	libexec/cups/filter/rastertobrlaser \
		share/cups/drv/brlaser.drv

.include <bsd.port.mk>
