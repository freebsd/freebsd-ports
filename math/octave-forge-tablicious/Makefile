PORTNAME=	octave-forge-tablicious
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS+=	libzmq.so:net/libzmq4

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	apjanke
GH_PROJECT=	octave-tablicious

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

.include <bsd.port.mk>
