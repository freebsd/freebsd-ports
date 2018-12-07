# $FreeBSD$

PORTNAME=	polylib
DISTVERSION=	5.22.5
CATEGORIES=	math
MASTER_SITES=	http://icps.u-strasbg.fr/polylib/polylib_src/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library of polyhedral functions

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-libgmp=${LOCALBASE} # can also be built w/out libgmp, in which case the suffix on some files changes. Not sure if/how this is useful.
USE_LDCONFIG=	yes

.include <bsd.port.mk>
