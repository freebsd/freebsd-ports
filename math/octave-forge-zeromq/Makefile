PORTNAME=	octave-forge-zeromq
PORTVERSION=	1.5.5
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libzmq.so:net/libzmq4

USES=		localbase octave pkgconfig

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
