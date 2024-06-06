PORTNAME=	octave-forge-signal
PORTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/control.tar.gz:math/octave-forge-control

USES=		octave

post-patch:
	${REINPLACE_CMD} s/-Wall// ${WRKSRC}/Makefile

.include <bsd.port.mk>
