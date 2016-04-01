# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xorriso
PORTVERSION=	1.3.4
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn-${PORTVERSION}

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	ISO image manipulation tool based on Libburnia

LICENSE=	GPLv2

BUILD_DEPENDS=	libburn>=1.1.0:devel/libburn \
		libisofs>=1.1.2:devel/libisofs
RUN_DEPENDS=	libburn>=1.1.0:devel/libburn \
		libisofs>=1.1.2:devel/libisofs

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool pathfix pkgconfig shebangfix
SHEBANG_FILES=	${WRKSRC}/frontend/xorriso-tcltk
USE_LDCONFIG=	yes

INFO=		xorrecord xorriso xorrisofs

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

.include <bsd.port.mk>
