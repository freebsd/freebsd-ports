PORTNAME=	octave-forge-automatic-differentiation
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	StevenWaldrip
GH_PROJECT=	Automatic-Differentiation

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GH_PROJECT}-${DISTVERSION}

RUN_DEPENDS+=	${TARBALLS_DIR}/sockets.tar.gz:math/octave-forge-sockets

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

do-build:
	@${DO_NADA}

NO_ARCH=	yes

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
