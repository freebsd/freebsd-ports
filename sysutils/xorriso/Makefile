# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xorriso
PORTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	libisoburn-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO image manipulation tool based on Libburnia

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libburn.so:devel/libburn \
		libisofs.so:devel/libisofs

GNU_CONFIGURE=	yes
USES=		gmake iconv libtool libedit pathfix pkgconfig shebangfix
SHEBANG_FILES=	${WRKSRC}/frontend/xorriso-tcltk
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		xorrecord xorriso xorrisofs

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

.include <bsd.port.mk>
