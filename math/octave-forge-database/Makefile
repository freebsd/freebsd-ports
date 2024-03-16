PORTNAME=	octave-forge-database
PORTVERSION=	2.4.4
PORTREVISION=	7
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		does not build with octave>=8

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/struct.tar.gz:math/octave-forge-struct

USES=		octave pgsql

GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} 's#endian.h#sys/endian.h#' ${WRKSRC}/wrap_endian.h

.include <bsd.port.mk>
