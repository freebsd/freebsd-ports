# New ports collection makefile for:    dclib
# Date created:                         Wed 10 Jul 2002
# Whom: Sverrir Valgeirsson <e96sv@yahoo.se> and
#	Amar Takhar <verm@drunkmonk.net> et al
#
# $FreeBSD$
#

PORTNAME=	dclib
PORTVERSION=	0.3.7
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/dcgui/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Direct connect interface library for dcgui

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
INSTALLS_SHLIB=	yes
USE_INC_LIBTOOL_VER=13

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's/-O2//g; s/-pedantic //g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
