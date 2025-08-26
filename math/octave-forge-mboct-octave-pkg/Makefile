PORTNAME=	octave-forge-mboct-octave-pkg
DISTVERSION=	0.1.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS+=	libgtest.so:devel/googletest

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	octave-user
GH_PROJECT=	mboct-octave-pkg

OCTAVE_SRC=	${GH_PROJECT}-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
