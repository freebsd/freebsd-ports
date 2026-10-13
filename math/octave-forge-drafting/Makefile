PORTNAME=	octave-forge-drafting
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libTKernel.so:cad/opencascade

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	pr0m1th3as
GH_PROJECT=	${OCTAVE_PKGNAME}

OCTAVE_SRC=		${GH_PROJECT}-release-${DISTVERSION}

post-patch:
	${REINPLACE_CMD} 's+/usr/local+${PREFIX}+' ${WRKSRC}/Makefile

.include <bsd.port.mk>
