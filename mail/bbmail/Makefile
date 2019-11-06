# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bbmail
PORTVERSION=	0.9.3
CATEGORIES=	mail
MASTER_SITES=	SF/bbtools/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool intended for Blackbox that checks for new mail

LICENSE=	GPLv2+

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libbt.pc:x11-wm/blackbox

USES=		pkgconfig xorg
USE_XORG=	xext
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bbmail man/man1/bbmail.1.gz share/bbtools/bbmail.rc

.include <bsd.port.mk>
