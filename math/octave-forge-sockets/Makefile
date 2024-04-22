PORTNAME=	octave-forge-sockets
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS+=	gsed:textproc/gsed

USES=		gmake octave

post-patch:
	${REINPLACE_CMD} 's/sed/gsed/g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
