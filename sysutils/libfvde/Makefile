# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfvde
PORTVERSION=	20160918
DISTVERSIONPREFIX=	experimental-
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/libyal/libfvde/releases/download/${PORTVERSION}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools for reading FileVault (FVDE) encrypted volumes

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USES=		fuse gettext libtool pathfix pkgconfig python ssl
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LIBS+=		-L${OPENSSLLIB}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
