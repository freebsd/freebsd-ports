PORTNAME=	octave-forge-automatic-differentiation
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/sockets.tar.gz:math/octave-forge-sockets

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	StevenWaldrip
GH_PROJECT=	Automatic-Differentiation

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
