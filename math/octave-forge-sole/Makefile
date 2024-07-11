PORTNAME=	octave-forge-sole
PORTVERSION=	0.1.1
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	https://sourceforge.net/projects/sole/files/latest/
DISTNAME=	download
DIST_SUBDIR=	octave-forge/sole

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/bim.tar.gz:math/octave-forge-bim

USES=		octave

OCTAVE_SRC=		${OCTAVE_PKGNAME}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
