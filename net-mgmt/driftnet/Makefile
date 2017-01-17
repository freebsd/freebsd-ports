# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	driftnet
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to grab images out of (your) TCP connections

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng16.so:graphics/png
BUILD_DEPENDS=	makedepend:devel/makedepend

GNU_CONFIGURE=	yes
USES=		compiler:gcc-c++11-lib gettext-runtime gmake jpeg localbase:ldflags pkgconfig
USE_GNOME=	gtk20
USE_XORG=	x11 xext xi

PLIST_FILES=	bin/driftnet man/man1/driftnet.1.gz
PORTDOCS=	*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
