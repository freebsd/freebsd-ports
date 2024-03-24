PORTNAME=	octave-forge-control
DISTVERSIONPREFIX=	control-
DISTVERSION=	4.0.1
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

#post-patch:
	#${MV} ${WRKSRC}/TG04BX.f ${WRKSRC_slicot}/src

post-patch:
	${REINPLACE_CMD} -e '/SC_SMOD.*\:\=/s+\.\./slicot\-reference+${WRKSRC_slicot}'+ ${WRKSRC}/Makefile

.include <bsd.port.mk>
