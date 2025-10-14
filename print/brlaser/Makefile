PORTNAME=	brlaser
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.8
CATEGORIES=	print

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Brother laser printer driver
WWW=		https://github.com/Owl-Maintain/brlaser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcups.so:print/cups

USES=		cmake:insource,noninja compiler:c++11-lang

USE_GITHUB=	yes

GH_ACCOUNT=	Owl-Maintain
GH_PROJECT=	brlaser

PLIST_FILES=	libexec/cups/filter/rastertobrlaser \
		share/cups/drv/brlaser.drv

.include <bsd.port.mk>
