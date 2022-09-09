PORTNAME=	libdc1394
DISTVERSION=	2.2.6
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-2/${PORTVERSION}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	1394-based DC Control Library
WWW=		https://damien.douxchamps.net/ieee1394/libdc1394/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
