# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	dynare
PORTVERSION=	4.3.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.dynare.org/release/source/

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Software platform for handling a wide class of economic models

BUILD_DEPENDS=	${LOCALBASE}/include/boost/unordered_set.hpp:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes
USE_XZ=		yes

INFO=		dynare

OPTIONS_DEFINE=	OCTAVE MATLAB
OCTAVE_DESC=Enable compilation of MEX files for Octave
MATLAB_DESC=	Enable compilation of MEX files for MATLAB
OPTIONS_DEFAULT=	OCTAVE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MMATLAB)
CONFIGURE_ARGS+=	--disable-matlab
.endif

.if ${PORT_OPTIONS:MOCTAVE}
BUILD_DEPENDS+=		octave:${PORTSDIR}/math/octave
.else
CONFIGURE_ARGS+=	--disable-octave
.endif

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
