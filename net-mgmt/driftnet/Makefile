# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	driftnet
PORTVERSION=	1.1.5
DISTVERSIONPREFIX=	upstream/
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to grab images out of (your) TCP connections

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png
BUILD_DEPENDS=	makedepend:devel/makedepend

GNU_CONFIGURE=	yes
USES=		autoreconf gettext-runtime gmake jpeg localbase:ldflags pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk20
USE_XORG=	x11 xext xi

GH_ACCOUNT=	deiv

PLIST_FILES=	bin/driftnet man/man1/driftnet.1.gz
PORTDOCS=	*

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
