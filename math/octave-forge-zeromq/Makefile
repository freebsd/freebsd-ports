PORTNAME=	octave-forge-zeromq
DISTVERSIONPREFIX=	release-
PORTREVISION=	1
DISTVERSION=	1.5.6
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS+=	libzmq.so:net/libzmq4

USES=		localbase octave pkgconfig autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-zeromq

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
