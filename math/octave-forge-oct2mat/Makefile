PORTNAME=	octave-forge-oct2mat
PORTVERSION=	1.0.7
PORTREVISION=	30
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Old%20Monolithic%20Releases/R2009-06-07
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${OCTAVE_TARBALLS_DIR}/io.tar.gz:math/octave-forge-io

USES=			octave

GNU_CONFIGURE=	yes

WRKSRC=        ${WRKDIR}/${OCTAVE_SRC}

.include <bsd.port.mk>
