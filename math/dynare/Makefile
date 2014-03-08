# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	dynare
PORTVERSION=	4.4.2
CATEGORIES=	math
MASTER_SITES=	http://www.dynare.org/release/source/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Software platform for handling a wide class of economic models

BUILD_DEPENDS=	${LOCALBASE}/include/boost/unordered_set.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libumfpack.so:${PORTSDIR}/math/suitesparse \
		libmatio.so:${PORTSDIR}/math/matio

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USES=		fortran gmake
USE_XZ=		yes

INFO=		dynare

OPTIONS_DEFINE=		OCTAVE MATLAB
OCTAVE_DESC=		Enable compilation of MEX files for Octave
MATLAB_DESC=		Enable compilation of MEX files for MATLAB
OPTIONS_DEFAULT=	OCTAVE

MATLAB_CONFIGURE_ENABLE=	matlab
OCTAVE_CONFIGURE_ENABLE=	octave
OCTAVE_BUILD_DEPENDS=		octave:${PORTSDIR}/math/octave

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} "Follow instructions at http://www.freebsd.org/doc/handbook/linuxemu-matlab.html"
	@${ECHO_MSG} "on how to install MATLAB on FreeBSD"
	@${ECHO_MSG} "*******************************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
