PORTNAME=	octave-forge-communications
PORTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/signal.tar.gz:math/octave-forge-signal

USES=		octave autoreconf pkgconfig

GNU_CONFIGURE=	yes

MAKE_ENV+=	MKOCTFILE=mkoctfile

.include <bsd.port.mk>
