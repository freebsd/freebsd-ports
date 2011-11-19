# New ports collection makefile for:   dynare
# Date created:                Aug 17 2011
# Whom:                        Fernando Apesteguia <fernando.apesteguia@gmail.com>
#
# $FreeBSD$

PORTNAME=	dynare
PORTVERSION=	4.2.2
CATEGORIES=	math
MASTER_SITES=	http://www.dynare.org/download/dynare-4.2/source/dynare-4.2.2.tar.gz/at_download/file

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Software platform for handling a wide class of economic models

BUILD_DEPENDS=	${LOCALBASE}/include/boost/unordered_set.hpp:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_FORTRAN=	yes

OPTIONS+=	OCTAVE	"Enable compilation of MEX files for Octave"	on
OPTIONS+=	MATLAB	"Enable compilation of MEX files for MATLAB"	off

.if defined(WITHOUT_MATLAB)
CONFIGURE_ARGS+=	--disable-matlab
.endif

.if defined(WITHOUT_OCTAVE)
CONFIGURE_ARGS+=	--disable-octave
.else
BUILD_DEPENDS+=		octave:${PORTSDIR}/math/octave
.endif

do-fetch:
	fetch -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} http://www.dynare.org/download/dynare-4.2/source/${DISTNAME}${EXTRACT_SUFX}/at_download/file

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
