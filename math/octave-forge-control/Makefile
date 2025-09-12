PORTNAME=	octave-forge-control
DISTVERSIONPREFIX=	control-
DISTVERSION=	4.1.3
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave SLICOT:slicot
GH_PROJECT=	pkg-control SLICOT-Reference:slicot
GH_TAGNAME=	401037e:slicot

OCTAVE_SRC=	${GH_PROJECT}-control-${DISTVERSION}

GNU_CONFIGURE=	yes

MAKE_ARGS+=	SC_SMOD=${WRKSRC_slicot}

.include <bsd.port.mk>
